#ifndef DMP_IMAGE_H
#define DMP_IMAGE_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#pragma pack(push, 1)

// tamaño de la cabecera (normalmente vale con 0x28):
typedef struct HeaderBMP {
    uint32_t size_header;
    
    // ancho de la imagen
    uint32_t width_img;

    // altura de la imagen
    uint32_t height_img;

    // numero de planos de color, siempre a 1:
    uint16_t color_planes;

    /*
     * The number of bits per pixel(bits por pixel, si es
     * RGB = 8 * 3 = 24bits por pixel
     */
    uint16_t bit_pixel;
} HeaderBMP;
#define sizeof_header sizeof(HeaderBMP)

/*
 * Datos de la imagen que escribir tal cual sin alinear los campos.
 * ya que el formato lo requiere.
 */
typedef struct BMP_Image {
    uint16_t file_header;
    uint32_t size_img; // ?
    uint16_t reserve1;
    uint16_t reserve2;
    uint32_t offset_init_data;
    HeaderBMP header_bmp;

    // metodo de compresion(siempre a 0 para no compresion)
    uint32_t method_compresion;

    // tamaño de la imagen en crudo(sin contar la cabecera)
    uint32_t size_img_raw;

    // resolucion orizontal:
    uint32_t horizontal_resolution;

    // resolucion vertical:
    uint32_t vertical_resolution;

    /*
     * el número de colores en la paleta de colores,
     * o 0 para el valor predeterminado 2^n
     */
    uint32_t color_palette;

    /*
     * la cantidad de colores importantes utilizados, o 0 cuando todos
     * los colores son importantes; generalmente se ignora
     */
    uint32_t important_colors;
} BMP_Image;

typedef struct BMP_t
{
    BMP_Image image_metadata;

    // datos de la imagen(pixeles)
    uint8_t *image_data;
    uint32_t size_image_data;

    uint32_t bytesPerRow;
    uint32_t padding;
    uint32_t bytesPerRowWithPadding;
} BMP_t;
#pragma pack(pop)

void init_BMP_t(BMP_t* image);
void calc_image(BMP_t* image, uint32_t width, uint32_t height,
    const uint8_t const* data_raw, uint32_t size_data_raw,
    uint8_t** data_with_padding);
void write_image(const char *filename, BMP_t* image);
void print_image(BMP_t *image);
BMP_t* read_image(BMP_t* image, const char *filename);
void invert_colors(BMP_t* image);

#define get_size_with_padding(width, bytesPerRowWithPadding) (height * bytesPerRowWithPadding)

#endif