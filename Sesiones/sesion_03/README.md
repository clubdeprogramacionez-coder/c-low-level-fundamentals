# Sesión 3: Operadores bit a bit y máscaras

## 1. Objetivo de Aprendizaje
Aprender a manipular bits directamente para extraer, activar o desactivar información con máscaras y operaciones lógicas.

## 2. Lectura Guiada 
La memoria no es solo texto ni números grandes; en el fondo, todo se reduce a bits. Un bit es como un interruptor: está encendido o apagado. Los operadores bit a bit permiten leer y modificar esos interruptores sin necesidad de convertir todo a un valor humano. Una máscara es como una plantilla: te dice “solo quiero mirar estas posiciones” y deja el resto fuera. Cuando trabajas con hardware, flags, estados y control, esto es esencial porque muchos sistemas usan indicadores binarios en lugar de valores completos.

## 3. Temas de la Sesión
- AND, OR, XOR, NOT y desplazamiento.
- Máscaras para aislar bits.
- Manipulación de flags y estados.
- Relación entre bits, bytes y datos compactos.

## 4. Código de Explicación
```c
unsigned int mask = 0x0F;
unsigned int value = 0xB7;
unsigned int result = value & mask;

```

- `mask` tiene solo los 4 bits de interés activos.
- `&` conserva únicamente esos bits en `value`.
- El resultado muestra solo la porción filtrada, ignorando cualquier otra información del valor original.

```c
unsigned int state = 0b00101100;
state |= (1u << 5);
state &= ~(1u << 2);

```

- `|=` activa un bit concreto sin tocar los demás.
- `&= ~` desactiva un bit específico.
- La ejecución de estas operaciones es una forma directa de controlar flags o estados del sistema.

## 5. Tabla Comparativa

| Concepto | Qué ocurre | Por qué importa |
|---|---|---|
| AND (&) | Conserva solo bits activos en ambos operandos. | Útil para aislar campos dentro de un valor. |
| OR (|) | Activa bits seleccionados. | Se usa para activar flags o configuraciones. |
| XOR (^) | Invierte bits donde hay diferencias. | Útil para toggle o comparación bit a bit. |
| Desplazamiento (<<, >>) | Mueve bits a izquierda o derecha. | Permite preparar máscaras y escalar valores con facilidad. |

## 6. LABORATORIO 
*Como:* estudiante que trabaja con control y estados
*Quiero:* aislar y modificar bits específicos en un valor
*Para:* entender cómo los flags y los campos compactos se representan y operan en C
*Criterios de Aceptación:*
- [ ] El alumno usa al menos dos operadores bit a bit con explicación clara.
- [ ] El alumno identifica cómo una máscara selecciona bits específicos.
- [ ] El alumno explica qué significa activar o desactivar un flag.

## 7. PRÁCTICA - Instrucciones para Classroom
Revisa el archivo `practica.c` y localiza las operaciones con `&`, `|`, `^` y desplazamientos. Compara el valor original con la máscara aplicada y verifica el resultado en ejecución.

```bash
riscv64-unknown-elf-gcc -O0 practica.c -o practica
qemu-riscv64 ./practica
```

Checklist de Entregable:
- [ ] Revisé todas las operaciones bit a bit.
- [ ] Documenté la función de cada máscara.
- [ ] Verifiqué el resultado con ejecución real.

### CRITERIOS DE EVALUACIÓN 
Cada práctica vale 100 pts divididos así:
- **Compilación y Ejecución :** Compila con `riscv64-unknown-elf-gcc` sin warnings y corre en `qemu-riscv64`.
- **Visualización de Memoria :** Usa `printf("%p")`, `objdump -h`, `readelf` u otra evidencia; adjunta captura.
- **Comprensión :** Responde la Pregunta de Cierre con sus palabras, indicando DÓNDE vive cada dato y POR QUÉ.
- **Buenas prácticas :** Uso correcto de `free()`, nombres claros, comentarios de dirección y sin leaks.

## 8. Recursos Visuales
[IMAGEN SUGERIDA: Diagrama de un byte con una máscara sobre bits específicos resaltados.]

## 9. Pregunta de Cierre 
¿Por qué una máscara permite revisar solo parte de un valor sin destruir el resto, y por qué eso es tan útil cuando se manipulan flags o estados de hardware?
