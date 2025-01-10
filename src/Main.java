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
import javax.swing.*;
import java.awt.*;
import java.io.*;

import UintTypes.IntType;

public class Main extends JPanel {
    public Color[] datos = { // 6 * 3 = 18 colores
            new Color(255, 0, 0),     new Color(0, 255, 0),   new Color(0, 0, 255),
            new Color(255, 255, 0),   new Color(0, 255, 255), new Color(255, 0, 255),
            new Color(255, 255, 255), new Color(0, 0, 0),     new Color(255, 255, 255),
            new Color(125, 0, 0),     new Color(0, 125, 0),   new Color(0, 0, 125),
            new Color(125, 75, 0),    new Color(0, 125, 75),  new Color(75, 0, 125),
            new Color(125, 75, 75),   new Color(0, 125, 0),   new Color(75, 75, 125),
    };
    public byte[] datos_byte;

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        for (int x = 0; x <= 400; x++) {
            for (int y = 0; y <= 400; y++) {
                drawDot(g, datos[(x*y) % datos.length], x, y); // Drawing a pixel at (50, 50)
            }
        }
    }
    private void write_datos(String name_file){
        datos_byte = new byte[this.datos.length * 3];
        for (int i = 0, j = 0; i < this.datos.length; i++, j+=3){
            datos_byte[j]   = (byte) this.datos[i].getRed();
            datos_byte[j+1] = (byte) this.datos[i].getGreen();
            datos_byte[j+2] = (byte) this.datos[i].getBlue();
        }
        try {
            OutputStream img_file = new FileOutputStream(name_file);
            img_file.write(datos_byte, 0, datos_byte.length);
            img_file.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    private void drawDot(Graphics g, Color self_color, int x, int y) {
        g.setColor(self_color); // Set the color of the dot
        g.fillRect(x, y, 1, 1); // Draw a single pixel
    }

    public static void main(String[] args) {

        JFrame frame = new JFrame("Lol  mirame");
        Main dotDrawer = new Main();
        frame.add(dotDrawer);
        frame.setSize(200, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);

        dotDrawer.write_datos("img");

        byte[] datos = {
                /*(byte)0x96, (byte)0x3E, (byte)0x5E,
                (byte)0x4D, (byte)0x2E, (byte)0xE2,
                (byte)0x40, (byte)0x8B, (byte)0xE5,
                (byte)0xA3, (byte)0xDE, (byte)0x0E,
                (byte)0x28, (byte)0xE1, (byte)0x2F,
                (byte)0x8E, (byte)0x09, (byte)0xDD,
                (byte)0x37, (byte)0xE1, (byte)0xE3,
                (byte)0x10, (byte)0xDE, (byte)0x97,
                (byte)0x86, (byte)0x82, (byte)0xEE,
                (byte)0x80, (byte)0x97, (byte)0xED,
                (byte)0x79, (byte)0x2C, (byte)0xE2,
                (byte)0xDF, (byte)0x19, (byte)0x5D,
                (byte)0xF3, (byte)0x05, (byte)0x03,
                (byte)0x4F, (byte)0x04, (byte)0x2B,
                (byte)0x12, (byte)0x12, (byte)0x12,
                (byte)0x1B, (byte)0x06, (byte)0xDD*/
                (byte)0xFF, (byte)0x00, (byte)0x00,
                (byte)0x00, (byte)0xFF, (byte)0x00,
                (byte)0x00, (byte)0x00, (byte)0xFF,
                (byte)0x00, (byte)0xFF, (byte)0x00
        };
        BMP_Image imagen = new BMP_Image(3,6, dotDrawer.datos_byte);
        imagen.printBMPAttributes();
        System.out.println(imagen.create_BMP().toString());
        imagen.write_bmp_to_file("Lol.bmp");

        final int WIDTH = 400;
        final int HEIGHT = 400;

        byte[] datos2 = {
                0x11, 0x22, 0x33,
                0x44, 0x55, 0x66,
                0x77, (byte)0x88, (byte)0x99,
                0x11, 0x22, 0x33,
                0x44, 0x55, 0x66,
                0x77, (byte)0x88, (byte)0x99
        };
        imagen = new BMP_Image(3,2, datos2);
        imagen.printBMPAttributes();
        System.out.println(imagen.create_BMP().toString());
        imagen.write_bmp_to_file("example_java.bmp");

    /*
        try (ByteArrayOutputStream baos = new ByteArrayOutputStream()) {
            for (int y = HEIGHT - 1; y >= 0; y--) {  // Invertimos el orden de las filas
                for (int x = 0; x < WIDTH; x++) {
                    Color color = dotDrawer.datos[(x*y) % dotDrawer.datos.length];
                    baos.write(new byte[] {
                            (byte)color.getBlue(),   // BMP usa BGR
                            (byte)color.getGreen(),
                            (byte)color.getRed()
                    });
                }
                // Añadir padding si es necesario
                while (baos.size() % 4 != 0) {
                    baos.write(0);
                }
            }
            BMP_Image imagen_400_400 = new BMP_Image(WIDTH, HEIGHT, baos.toByteArray());
            imagen_400_400.printBMPAttributes();
            imagen_400_400.create_BMP();
            imagen_400_400.write_bmp_to_file("pruebas_lol.bmp");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }*/
    }

}