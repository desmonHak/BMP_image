#include "BMP_image.h"

int main(void) {
    BMP_t image;
    init_BMP_t(&image);

    uint8_t data[] = {
        0x11, 0x22, 0x33,
        0x44, 0x55, 0x66,
        0x77, 0x88, 0x99,
        
        0x11, 0x22, 0x33,
        0x44, 0x55, 0x66,
        0x77, 0x88, 0x99
    };

    uint8_t* data_with_padding;
    calc_image(&image, 3, 2, data, sizeof(data), &data_with_padding);
    print_image(&image);
    write_image("example_c.bmp", &image);

    puts("exit");
    return 0;
}