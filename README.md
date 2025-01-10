# BMP_image

----

Esta es una pequeña libreria para leer y escribir imagenes RGBs lineales en formato BMP windows.

![Imagen del fotmato BMP](The%20Structure%20of%20the%20Bitmap%20Image%20File%20(BMP).svg)

----

## Compilacion

La carpeta `example` contiene ejemplos que se pueden autocompilar usando ``linux.mk`` y ``windows.mk``:

```c
mingw32-make -f windows.mk
make -f linux.mk
```

Esto ejecutara los siguientes comandos:

```c
gcc -std=c99 -I. -masm=intel -D_ExceptionHandler -fdiagnostics-color=always  -O3 -Wno-unused-parameter -Wno-implicit-fallthrough -Wno-type-limits -Wno-unused-variable -Wno-pointer-sign -c BMP_image.c -o BMP_image.o
ar -rc libBMP_image.a BMP_image.o
ranlib libBMP_image.a
ar -t libBMP_image.a
gcc -std=c99 -I. -masm=intel -D_ExceptionHandler -fdiagnostics-color=always  -O3 -Wno-unused-parameter -Wno-implicit-fallthrough -Wno-type-limits -Wno-unused-variable -Wno-pointer-sign -I. ./examples/example1.c -L. -lBMP_image -o ./out/example1.exe
gcc -std=c99 -I. -masm=intel -D_ExceptionHandler -fdiagnostics-color=always  -O3 -Wno-unused-parameter -Wno-implicit-fallthrough -Wno-type-limits -Wno-unused-variable -Wno-pointer-sign -I. ./examples/example2.c -L. -lBMP_image -o ./out/example2.exe
gcc -std=c99 -I. -masm=intel -D_ExceptionHandler -fdiagnostics-color=always  -O3 -Wno-unused-parameter -Wno-implicit-fallthrough -Wno-type-limits -Wno-unused-variable -Wno-pointer-sign -I. ./examples/example3.c -L. -lBMP_image -o ./out/example3.exe
gcc -std=c99 -I. -masm=intel -D_ExceptionHandler -fdiagnostics-color=always  -O3 -Wno-unused-parameter -Wno-implicit-fallthrough -Wno-type-limits -Wno-unused-variable -Wno-pointer-sign -I. ./examples/example4.c -L. -lBMP_image -o ./out/example4.exe
```

Donde se genera la libreria `libBMP_image.a` y los ejecutables `example1.exe`, `example2.exe`, `example3.exe` y `example4.exe`. Para eso se usa el comando `ar` encargado de crear la libreria y el comando `ranlib` para actualizar los indices de la libreria.
Con la libreria generada se puede enlazad usando ``-L<ruta de la libreria> -l<nombre de la libreria>``, el nombre de la lib debe ponerse sin la palabra `lib` ni la extension `.a`.

----

## Licencia :

```c
Licencia Apache, Versión 2.0 con Modificación

Copyright 2023 Desmon

Se concede permiso, de forma gratuita, a cualquier persona que obtenga una copia de este software y archivos de documentación asociados (el "Software"), para tratar el Software sin restricciones, incluidos, entre otros, los derechos de uso, copia, modificación, fusión, publicación, distribución, sublicencia y/o venta de copias del Software, y para permitir a las personas a quienes se les proporcione el Software hacer lo mismo, sujeto a las siguientes condiciones:

El anterior aviso de copyright y este aviso de permiso se incluirán en todas las copias o partes sustanciales del Software.

EL SOFTWARE SE PROPORCIONA "TAL CUAL", SIN GARANTÍA DE NINGÚN TIPO, EXPRESA O IMPLÍCITA, INCLUYENDO PERO NO LIMITADO A LAS GARANTÍAS DE COMERCIABILIDAD, IDONEIDAD PARA UN PROPÓSITO PARTICULAR Y NO INFRACCIÓN. EN NINGÚN CASO LOS TITULARES DEL COPYRIGHT O LOS TITULARES DE LOS DERECHOS DE AUTOR SERÁN RESPONSABLES DE NINGÚN RECLAMO, DAÑO U OTRA RESPONSABILIDAD, YA SEA EN UNA ACCIÓN DE CONTRATO, AGRAVIO O DE OTRA MANERA, QUE SURJA DE, FUERA DE O EN CONEXIÓN CON EL SOFTWARE O EL USO U OTRO TIPO DE ACCIONES EN EL SOFTWARE.

Además, cualquier modificación realizada por terceros se considerará propiedad del titular original de los derechos de autor. Los titulares de derechos de autor originales no se responsabilizan de las modificaciones realizadas por terceros.

Queda explícitamente establecido que no es obligatorio especificar ni notificar los cambios realizados entre versiones, ni revelar porciones específicas de código modificado.



Apache License, Version 2.0 with Modification

Copyright 2023 Desmon

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do the same, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR THE AUTHORIZED COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Furthermore, any modifications made by third parties shall be deemed to be the property of the original copyright holder. The original copyright holders shall not be liable for modifications made by third parties.

It is explicitly stated that it is not required to specify or notify changes made between versions, or to disclose specific portions of modified code.



Лицензия Apache, версия 2.0 с модификациями

Авторские права принадлежат Desmon, 2023 г.

Любому лицу, получившему копию данного программного обеспечения и связанных с ним файлов документации («Программное обеспечение»), бесплатно предоставляется разрешение на работу с Программным обеспечением без ограничений, включая, помимо прочего, права на использование, копирование, изменение, слияние, публикацию, распространение, сублицензирование и/или продажу копий Программного обеспечения, а также разрешать лицам, которым предоставляется Программное обеспечение, делать то же самое при соблюдении следующих условий:

Вышеупомянутое уведомление об авторских правах и данное уведомление о разрешении будут включены во все копии или существенные части Программного обеспечения.

ПРОГРАММНОЕ ОБЕСПЕЧЕНИЕ ПРЕДОСТАВЛЯЕТСЯ «КАК ЕСТЬ», БЕЗ КАКИХ-ЛИБО ГАРАНТИЙ, ЯВНЫХ ИЛИ ПОДРАЗУМЕВАЕМЫХ, ВКЛЮЧАЯ, НО НЕ ОГРАНИЧИВАЯСЬ, ГАРАНТИЯМИ ТОВАРНОЙ ЦЕННОСТИ, ПРИГОДНОСТИ ДЛЯ ОПРЕДЕЛЕННОЙ ЦЕЛИ И НЕНАРУШЕНИЯ ПРАВ. НИ ПРИ КАКИХ ОБСТОЯТЕЛЬСТВАХ АВТОРСКИЕ ПРАВА ИЛИ ОБЛАДАТЕЛИ АВТОРСКИХ ПРАВ НЕ НЕСУТ ОТВЕТСТВЕННОСТИ ЗА ЛЮБЫЕ ПРЕТЕНЗИИ, УБЫТКИ ИЛИ ДРУГУЮ ОТВЕТСТВЕННОСТЬ, БУДЬ В ДЕЙСТВИЯХ ПО КОНТРАКТУ, ПРАВОНАРУШЕНИЮ ИЛИ ДРУГИМ ОБРАЗОМ, ВОЗНИКАЮЩИМ ИЗ, ИЗ ИЛИ В СВЯЗИ С ПРОГРАММНЫМ ОБЕСПЕЧЕНИЕМ ИЛИ ИСПОЛЬЗОВАНИЕМ ИЛИ ДРУГИМИ ДЕЙСТВИЯМИ. В ПРОГРАММНОЕ ОБЕСПЕЧЕНИЕ.

Кроме того, любые изменения, внесенные третьими лицами, будут считаться собственностью первоначального правообладателя. Первоначальные владельцы авторских прав не несут ответственности за изменения, внесенные третьими лицами.

Прямо указано, что не обязательно указывать или уведомлять об изменениях, внесенных между версиями, а также раскрывать определенные части измененного кода.



Apache ライセンス、バージョン 2.0 (修正あり)

Copyright 2023 Desmon

このソフトウェアおよび関連ドキュメント ファイル (以下「ソフトウェア」) のコピーを入手した人には、使用、複製、変更する権利を含むがこれらに限定されない、制限なくソフトウェアを取り扱う許可が無料で与えられます。以下の条件に従って、本ソフトウェアのコピーの合併、出版、頒布、サブライセンスおよび/または販売を行うこと、および本ソフトウェアが提供される者が同様のことを行うことを許可すること。

上記の著作権表示およびこの許可通知は、ソフトウェアのすべてのコピーまたは主要部分に含まれます。

ソフトウェアは「現状のまま」提供され、明示的か黙示的かを問わず、商品性、特定目的への適合性、および非侵害の保証を含むがこれらに限定されない、いかなる種類の保証も行われません。いかなる場合においても、著作権者または著作権者は、契約行為、不法行為、その他の行為を問わず、ソフトウェアまたは使用またはその他の行為に起因または関連して生じる、いかなる請求、損害、またはその他の責任に対しても責任を負わないものとします。でソフトウェア。

さらに、第三者によって行われた変更は、元の著作権所有者の財産とみなされます。元の著作権者は、第三者による改変に対して責任を負いません。

バージョン間で行われた変更を指定または通知したり、変更されたコードの特定の部分を開示したりすることは義務ではないことが明示されています。
```

----

## Estructuras de la libreria

DIB header / BITMAPV55HEADER:
Esta estructura forma parte de la cabecera del archivo BMP. Esta debe escribirse sin que los campos miembro esten alineados.

```c
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
```

Estructura simplificada de la cabecera del archivo BMP:
Esta estructura es la cabecera del archivo BMP, esta estructura se utiliza para escribir la cabecera del archivo BMP y se hace una escritura en crudo por lo que sus campos miembros tampoco deben estar alineados. En esta estructura no se define todos los posibles campos de la cabecera del archivo BMP, solo los basicos y necesarios para la escritura de la cabecera de archivos BMP simples. Usted puede redefinir esta estructura para que contenga todos los campos de la cabecera del archivo BMP, que necesite.

```c
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
```

Estructura de informacion asociada con la imagen (``BMP_t``):
Esta estructura contiene la informacion asociada con la imagen, como tal ninguno de sus datos se escriben en la imagen, pero permite saber cuanto ocupa la imagen en bytes, cuanto ocupa el ``padding``. `bytesPerRowWithPadding` te permite saber el número total de bytes por fila de la imagen, incluyendo el padding. bytesPerRow permite saber el número de bytes que ocupa una fila de píxeles en la imagen, sin incluir el padding, representa el numero real de pixeles por fila.
El miembro `image_metadata` contiene la informacion de la imagen, como el ancho, alto, numero de bits por pixel, numero de planos de color, etc, que seran escritos en la cabecera del archivo BMP, mientras que `image_data` es un campo usado para almacenar el buffer leeido y el buffer escrito en los archivos.

```c
typedef struct BMP_t
{
    BMP_Image image_metadata;

    // datos de la imagen(pixeles)
    uint8_t *image_data;            // ESTE BUFFER DEBE LIBERARSE POR EL PROGRAMADOR!!!
    uint32_t size_image_data;

    uint32_t bytesPerRow;
    uint32_t padding;
    uint32_t bytesPerRowWithPadding;
} BMP_t;
```

## Funciones

```c
void init_BMP_t(BMP_t* image);
void calc_image(BMP_t* image, uint32_t width, uint32_t height,
    const uint8_t const* data_raw, uint32_t size_data_raw,
    uint8_t** data_with_padding);
void write_image(const char *filename, BMP_t* image);
void print_image(BMP_t *image);
BMP_t* read_image(BMP_t* image, const char *filename);
void invert_colors(BMP_t* image);
```

### ``init_BMP_t``
Inicializa una estructura ``BMP_t`` con valores predeterminados para una imagen BMP. Configura los metadatos de la imagen con información de encabezado BMP estándar e inicializa otros campos a cero o con valores predeterminados.

### ``calc_image``
Calcula y configura la estructura de datos de imagen para una imagen BMP:

- Calcula los tamaños de fila con y sin relleno
- Establece las dimensiones de la imagen en los metadatos
- Asigna memoria para los datos de la imagen añadiendo relleno
- Copia datos de imagen sin procesar en el búfer recién asignado y agrega relleno según sea necesario

### ``print_image``
Imprime los metadatos y la información clave de una imagen BMP, incluidos:

- Detalles del encabezado (tamaño, dimensiones, profundidad de color)
- Tamaño de la imagen y método de compresión
- Información de resolución y color
- Tamaños de fila y detalles de relleno
- Puntero a los datos de la imagen

### ``write_image``
Escribe una imagen BMP en un archivo:

- Abre el archivo especificado para escritura
- Escribe los metadatos de la imagen en el archivo
- Escribe los datos de la imagen (incluido el relleno) en el archivo

### ``read_image``
Lee una imagen BMP de un archivo:

- Abre el archivo especificado para leer
- Lee los metadatos de la imagen
- Calcula los tamaños de fila y el relleno
- Asigna memoria para los datos de la imagen
- Lee los datos de la imagen fila por fila, manejando el relleno

### ``invert_colors``
Invierte los colores de una imagen BMP:

- Asigna un nuevo búfer para la imagen invertida
- Recorre cada píxel e invierte su color (255 - valor original)
- Copia los bytes de relleno sin modificaciones
- Reemplaza los datos de la imagen original con los datos invertidos

----