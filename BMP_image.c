
#ifndef DMP_IMAGE_C
#define DMP_IMAGE_C

#include "BMP_image.h"

void init_BMP_t(BMP_t* image) {
    //memset(&(image->image_metadata), 0, sizeof(BMP_Image));
    image->image_data = NULL;

    image->image_metadata = (BMP_Image) {
        .file_header = 0x4D42,
        .size_img = 0,
        .reserve1 = 0,
        .reserve2 = 0,

        /*
         * 0E 	14 	4 	the size of this header, in bytes (40) 
         * https://en.wikipedia.org/wiki/BMP_file_format
         */
        .offset_init_data = 0x36,
        .header_bmp = (HeaderBMP){
            .size_header = 0x28,
            .width_img = 0,
            .height_img = 0,
            .color_planes = 1,
            .bit_pixel = 24,
        },
        .method_compresion = 0,
        .size_img_raw = 0,
        .horizontal_resolution = 0,
        .vertical_resolution = 0,
        .color_palette = 0,
        .important_colors = 0,
    };
}

void calc_image(BMP_t* image, uint32_t width, uint32_t height,
    const uint8_t const* data_raw, uint32_t size_data_raw,
    uint8_t** data_with_padding
) {
    assert(data_raw != NULL);
    assert(data_with_padding != NULL);


    // escritura de metadatos:

    image->bytesPerRow = width * 3; // 3 bytes por pixel (RGB)
    image->padding = (4 - (image->bytesPerRow % 4)) % 4;
    image->bytesPerRowWithPadding = image->bytesPerRow + image->padding;

    // asignar los tamaños de la imagen
    image->image_metadata.header_bmp.width_img  = width;
    image->image_metadata.header_bmp.height_img = height;

    // tamaño de los datos de la imagen sin el padding
    image->image_metadata.size_img_raw = size_data_raw;

    // no es del todo correcto sumar como tamaño de bitmap header 0x36,
        // pero como en este caso no se usa valores opcionales, se puede hacer
    image->image_metadata.size_img = image->image_metadata.size_img_raw +
        image->image_metadata.offset_init_data; // 0x36*/

    // crear el buffer para los datos con padding que seran escritos
    image->size_image_data = image->bytesPerRowWithPadding * height;
    *data_with_padding = calloc(image->size_image_data, sizeof(uint8_t));
    assert(*data_with_padding != NULL);

    uint8_t* ptr_cpy_data = *data_with_padding;

    puts("!");
    // copiar los datos de la imagen en crudo generando el padding
    for (int y = 0; y < height; y++) {
        memset(*data_with_padding + y * image->bytesPerRowWithPadding, 0, image->bytesPerRowWithPadding);
        memcpy(*data_with_padding + y * image->bytesPerRowWithPadding, data_raw + y * image->bytesPerRow, image->bytesPerRow);
    }


    image->image_data = *data_with_padding;


    // Guardar el puntero en la estructura
    image->image_data = ptr_cpy_data;
}

void print_image(BMP_t *image) {
    printf("BMP Image:\n");
    printf("Header:\n");
    printf("  The size of this header Windows BITMAPINFOHEADER: %d (0x28?)\n", image->image_metadata.header_bmp.size_header);
    printf("  Size: %u\n", image->image_metadata.header_bmp.size_header);
    printf("  Width: %u\n", image->image_metadata.header_bmp.width_img);
    printf("  Height: %u\n", image->image_metadata.header_bmp.height_img);
    printf("  Color Planes: %u\n", image->image_metadata.header_bmp.color_planes);
    printf("  Bit per Pixel: %u\n", image->image_metadata.header_bmp.bit_pixel);
    printf("Offset Init Data: %u\n", image->image_metadata.offset_init_data);
    printf("Size Image: %u\n", image->image_metadata.size_img);
    printf("Method Compresion: %u\n", image->image_metadata.method_compresion);
    printf("Size Image Raw: %u\n", image->image_metadata.size_img_raw);
    printf("Horizontal Resolution: %u\n", image->image_metadata.horizontal_resolution);
    printf("Vertical Resolution: %u\n", image->image_metadata.vertical_resolution);
    printf("Color Palette: %u\n", image->image_metadata.color_palette);
    printf("Important Colors: %u\n", image->image_metadata.important_colors);
    printf("Bytes Per Row: %u\n", image->bytesPerRow);
    printf("Padding: %u\n", image->padding);
    printf("Bytes Per Row With Padding: %u\n", image->bytesPerRowWithPadding);
    printf("Image Data: 0x%p\n", image->image_data);
    printf("Size image Data %d\n", image->size_image_data);
}

void write_image(const char *filename, BMP_t* image) {
    FILE* fd = fopen(filename, "wb");
    assert(fd != NULL);

    // escribir los metadatos de la imagen
    fwrite(&(image->image_metadata), sizeof(BMP_Image), 1, fd);
    fwrite(image->image_data, image->size_image_data, 1, fd);

    fclose(fd);
}

BMP_t* read_image(BMP_t* image, const char *filename) {
    if (image == NULL) {
        return NULL;
    }

    FILE* fd = fopen(filename, "rb");
    if (fd == NULL) {
        return NULL;
    }

    // Leer los metadatos de la imagen
    if (fread(&(image->image_metadata), sizeof(BMP_Image), 1, fd) != 1) {
        // Manejar error de lectura
        free(image);
        fclose(fd);
        return NULL;
    }

    // Calcular tamaños y padding
    image->bytesPerRow = image->image_metadata.header_bmp.width_img * 3;
    image->padding = (4 - (image->bytesPerRow % 4)) % 4;
    image->bytesPerRowWithPadding = image->bytesPerRow + image->padding;
    image->size_image_data = image->bytesPerRowWithPadding * image->image_metadata.header_bmp.height_img;


    image->image_data = malloc(image->size_image_data);
    if (image->image_data == NULL) {
        free(image);
        fclose(fd);
        return NULL;
    }

    uint8_t* row_buffer = malloc(image->bytesPerRowWithPadding);
    if (row_buffer == NULL) {
        free(image->image_data);
        free(image);
        fclose(fd);
        return NULL;
    }

    for (int y = 0; y < image->image_metadata.header_bmp.height_img; y++) {
        if (fread(row_buffer, image->bytesPerRowWithPadding, 1, fd) != 1) {
            free(row_buffer);
            free(image->image_data);
            free(image);
            fclose(fd);
            return NULL;
        }
        memcpy(image->image_data + y * image->bytesPerRow, row_buffer, image->bytesPerRow);
    }

    free(row_buffer);
    fclose(fd);
    return image;
}

void invert_colors(BMP_t* image) {
    // Create a new buffer for the inverted image
    uint8_t* inverted_data = malloc(image->size_image_data);
    if (inverted_data == NULL) {
        free(image->image_data);
    }

    // Copiar el byte de padding sin invertirlo
    int width = image->image_metadata.header_bmp.width_img;
    int height = image->image_metadata.header_bmp.height_img;

    // Iterar sobre cada fila de la imagen
    for (int y = 0; y < height; y++) {
        // Iterar sobre cada byte de datos de píxeles en la fila
        for (int x = 0; x < image->bytesPerRow; x++) {
            // Calcular el índice del byte actual en el array de datos
            int index = y * image->bytesPerRow + x;
            // Invertir el valor del byte (255 - valor original)
            inverted_data[index] = 255 - image->image_data[index];
        }
        // Manejar los bytes de padding al final de cada fila
        for (int x = image->bytesPerRow; x < image->bytesPerRowWithPadding; x++) {
            // Calcular el índice del byte de padding
            int index = y * image->bytesPerRowWithPadding + x;
            // Copiar el byte de padding sin invertirlo
            inverted_data[index] = image->image_data[index];
        }
    }

    // liberar datos de la imagen original
    free(image->image_data);
    image->image_data = inverted_data;
}

#endif