#include "BMP_image.h"

int main() {
    BMP_t image;
    init_BMP_t(&image);

    read_image(&image, "random_image.bmp");
    print_image(&image);

    invert_colors(&image);
    print_image(&image);

    // escribir datos de la nueva imagen
    write_image("random_image_invertido.bmp", &image);

    // liberar memoria
    free(image.image_data);

    puts("exit");
    return 0;
}