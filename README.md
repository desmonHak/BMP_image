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
BMP_image.o
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