# Sesión 15: CSR, MMIO y acceso a hardware

## 1. Objetivo de Aprendizaje
Comprender cómo la CPU expone registros del sistema y cómo el software accede a periféricos mediante memoria mapeada.

## 2. Lectura Guiada 
En un sistema embebido, la CPU no solo ejecuta instrucciones; también comunica el estado del procesador y controla periféricos. Los CSR son registros del sistema que permiten ver o modificar ese estado. MMIO significa que un dispositivo se accede como si fuera memoria: se lee y escribe una dirección física concreta para controlar una pieza de hardware. Esto es similar a hablarle a un módulo con una dirección conocida. Es decir, la computadora no vive solo en los datos del programa; también tiene puerta de entrada a cosas externas.

## 3. Temas de la Sesión
- CSR: Control and Status Registers.
- MMIO y periféricos mapeados en memoria.
- Acceso a hardware desde C y uso de `volatile`.
- Diferencia entre memoria normal y dispositivos físicos.

## 4. Código de Explicación
```c
volatile uint32_t *uart = (uint32_t *)0x10000000;
*uart = 0x41;

```

- Ese puntero apunta a un periférico real, no a un dato normal.
- El uso de `volatile` evita que el compilador optimice la operación como si no tuviera efecto.

```c
unsigned int csr = 0;
asm volatile ("csrr %0, mstatus\n\t" : "=r"(csr));

```

- La lectura de un CSR es una operación del sistema.
- No es un acceso a memoria ordinaria, sino a un registro del propio procesador.

## 5. Tabla Comparativa

| Concepto | Qué ocurre | Por qué importa |
|---|---|---|
| CSR | Registro del sistema. | Controla estado, configuración o interrupciones. |
| MMIO | Periférico accesible a través de memoria. | Permite interactuar con hardware usando direcciones. |
| `volatile` | Evita optimizaciones incorrectas. | Hace que la lectura o escritura real ocurra cada vez. |
| Memoria normal | Espacio para datos del programa. | No representa un dispositivo físico. |

## 6. LABORATORIO 
*Como:* estudiante de sistemas embebidos
*Quiero:* acceder a registros de hardware y entender la diferencia entre memoria normal y memoria mapeada
*Para:* interactuar con periféricos y comprender el funcionamiento interno de un sistema en tiempo real
*Criterios de Aceptación:*
- [ ] El alumno identifica la diferencia entre memoria normal y MMIO.
- [ ] El alumno explica la función de un CSR y un registro de control.
- [ ] El alumno relaciona el acceso a hardware con `volatile` y direcciones concretas.

## 7. PRÁCTICA - Instrucciones para Classroom
Revisa el archivo `practica.c` y observa si el código comprende acceso a hardware, registradores o direcciones de periféricos. Si presenta MMIO o CSR, identifica la dirección y explica si es memoria normal o un dispositivo.

```bash
riscv64-unknown-elf-gcc -O0 practica.c -o practica
qemu-riscv64 ./practica
```

Checklist de Entregable:
- [ ] Identifiqué el uso de MMIO o CSR.
- [ ] Explicité la diferencia entre un dato y un periférico.
- [ ] Validé la necesidad de `volatile` para acceso real.

## 8. Recursos Visuales
[IMAGEN SUGERIDA: Diagrama de la CPU con buses, CSR y periféricos conectados mediante MMIO.]

## 9. Pregunta de Cierre 
¿Por qué no basta con una variable normal para interactuar con hardware, y qué cambia cuando una dirección representa un registro de control o un periférico físico?
