/*
 * Licencia Apache, Versión 2.0 con Modificación
 *
 * Copyright 2023 Desmon
 *
 * Se concede permiso, de forma gratuita, a cualquier persona que obtenga una copia
 * de este software y archivos de documentación asociados (el "Software"), para
 * tratar el Software sin restricciones, incluidos, entre otros, los derechos de
 * uso, copia, modificación, fusión, publicación, distribución, sublicencia y/o
 * venta de copias del Software, y para permitir a las personas a quienes se les
 * proporcione el Software hacer lo mismo, sujeto a las siguientes condiciones:
 * El anterior aviso de copyright y este aviso de permiso se incluirán en todas
 * las copias o partes sustanciales del Software.
 *
 * EL SOFTWARE SE PROPORCIONA "TAL CUAL", SIN GARANTÍA DE NINGÚN TIPO, EXPRESA O
 * IMPLÍCITA, INCLUYENDO PERO NO LIMITADO A LAS GARANTÍAS DE COMERCIABILIDAD,
 * IDONEIDAD PARA UN PROPÓSITO PARTICULAR Y NO INFRACCIÓN. EN NINGÚN CASO LOS
 * TITULARES DEL COPYRIGHT O LOS TITULARES DE LOS DERECHOS DE AUTOR SERÁN
 * RESPONSABLES DE NINGÚN RECLAMO, DAÑO U OTRA RESPONSABILIDAD, YA SEA EN UNA
 * ACCIÓN DE CONTRATO, AGRAVIO O DE OTRA MANERA, QUE SURJA DE, FUERA DE O EN
 * CONEXIÓN CON EL SOFTWARE O EL USO U OTRO TIPO DE ACCIONES EN EL SOFTWARE.
 *
 * Además, cualquier modificación realizada por terceros se considerará propiedad
 * del titular original de los derechos de autor. Los titulares de derechos de
 * autor originales no se responsabilizan de las modificaciones realizadas por terceros.
 * Queda explícitamente establecido que no es obligatorio especificar ni notificar
 * los cambios realizados entre versiones, ni revelar porciones específicas de
 * código modificado.
 */

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