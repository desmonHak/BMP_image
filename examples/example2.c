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
