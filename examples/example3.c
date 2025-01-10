#include "BMP_image.h"

int main() {
    BMP_t image;
    init_BMP_t(&image);
    read_image(&image, "../nino_RGBs_lineal.bmp");
    print_image(&image);


    // Create a new buffer for the inverted image
    uint8_t* inverted_data = malloc(image.size_image_data);
    if (inverted_data == NULL) {
        free(image.image_data);
        return 1;
    }

    // Copiar el byte de padding sin invertirlo
    int width = image.image_metadata.header_bmp.width_img;
    int height = image.image_metadata.header_bmp.height_img;

    // Iterar sobre cada fila de la imagen
    for (int y = 0; y < height; y++) {
        // Iterar sobre cada byte de datos de píxeles en la fila
        for (int x = 0; x < image.bytesPerRow; x++) {
            // Calcular el índice del byte actual en el array de datos
            int index = y * image.bytesPerRow + x;
            // Invertir el valor del byte (255 - valor original)
            inverted_data[index] = 255 - image.image_data[index];
        }
        // Manejar los bytes de padding al final de cada fila
        for (int x = image.bytesPerRow; x < image.bytesPerRowWithPadding; x++) {
            // Calcular el índice del byte de padding
            int index = y * image.bytesPerRowWithPadding + x;
            // Copiar el byte de padding sin invertirlo
            inverted_data[index] = image.image_data[index];
        }
    }

    // liberar datos de la imagen original
    free(image.image_data);
    image.image_data = inverted_data;

    // escribir datos de la nueva imagen
    write_image("nino_invertido.bmp", &image);

    print_image(&image);
    
    // liberar memoria
    free(image.image_data);

    puts("exit");
    return 0;
}