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
#include <stdlib.h>
#include <time.h>

#define WIDTH 1024
#define HEIGHT 2048

int main(void) {
    BMP_t image;
    init_BMP_t(&image);

    // Crear un buffer de 1024 * 2048 * 3 (para RGB) con valores aleatorios
    uint8_t* data = malloc(WIDTH * HEIGHT * 3);
    if (data == NULL) {
        printf("Error: No se pudo asignar memoria para los datos de la imagen.\n");
        return 1;
    }

    // Inicializar el generador de números aleatorios
    srand(time(NULL));

    // Llenar el buffer con valores aleatorios
    for (int i = 0; i < WIDTH * HEIGHT * 3; i++) {
        data[i] = rand() % 256;  // Valores aleatorios entre 0 y 255
    }

    uint8_t* data_with_padding;
    calc_image(&image, WIDTH, HEIGHT, data, WIDTH * HEIGHT * 3, &data_with_padding);
    print_image(&image);
    write_image("random_image.bmp", &image);

    // Liberar la memoria
    free(data);
    free(data_with_padding);

    puts("exit");
    return 0;
}
