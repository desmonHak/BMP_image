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
import UintTypes.IntType;

import UintTypes.IntType_type;

public class IntType_forBMP extends IntType {
    IntType_type type_required = null;
    public IntType_forBMP(byte n1, byte n2) {
        super(n1, n2);
        this.type_required = IntType_type.uint16_t; // indica el valor que se requiere para este campo
    }
    public IntType_forBMP(short n1) {
        super(n1);
        this.type_required = IntType_type.uint16_t;
    }

    public IntType_forBMP(IntType n1, IntType n2) {
        super(n1, n2);
        this.type_required = IntType_type.uint_unknow_t;
    }

    public IntType_forBMP(byte n1, byte n2, byte n3, byte n4, byte n5, byte n6, byte n7, byte n8) {
        super(n1, n2, n3, n4, n5, n6, n7, n8);
        this.type_required = IntType_type.uint64_t;
    }
    public IntType_forBMP(long n1) {
        super(n1);
        this.type_required = IntType_type.uint64_t;
    }

    public IntType_forBMP(byte n1, byte n2, byte n3, byte n4) {
        super(n1, n2, n3, n4);
        this.type_required = IntType_type.uint32_t;
    }
    public IntType_forBMP(int n1) {
        super(n1);
        this.type_required = IntType_type.uint32_t;
    }

    public IntType_forBMP(byte n1) {
        super(n1);
        this.type_required = IntType_type.uint8_t;
    }
}
