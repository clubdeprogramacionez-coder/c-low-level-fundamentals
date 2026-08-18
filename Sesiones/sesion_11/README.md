# Sesión 11: Uniones, bitfields y endianness

## 1. Objetivo de Aprendizaje
Entender cómo un mismo bloque de memoria puede interpretarse de distintas formas con uniones, bitfields y orden de bytes.

## 2. Lectura Guiada 
La memoria no siempre se lee igual. El mismo conjunto de bytes puede representar un entero, una secuencia de caracteres o varias banderas según cómo lo interpretes. Las uniones permiten ver el mismo bloque desde distintos ángulos, mientras que los bitfields compactan varios indicadores en pocos bits. El endianness completa la historia: algunos sistemas guardan primero el byte menos significativo y otros el más significativo. Esto significa que dos máquinas pueden almacenar la misma palabra de forma distinta y producir resultados diferentes si no se maneja bien.

## 3. Temas de la Sesión
- Uniones y superposición de memoria.
- Bitfields para compactar banderas.
- Little-endian y big-endian.
- Interpretación del mismo bloque de bytes con distintos tipos.

## 4. Código de Explicación
```c
union U {
    uint32_t value;
    uint8_t bytes[4];
};

```

- La unión comparte la misma memoria para dos interpretaciones: como entero y como bytes.
- Esto permite observar cómo se almacena el valor en el sistema actual.

```c
struct Flags {
    unsigned int a : 1;
    unsigned int b : 3;
    unsigned int c : 4;
};

```

- Los bitfields permiten guardar varios indicadores en un espacio mínimo.
- Eso es útil cuando se quiere representar estados con pocos bits y no se desea gastar más espacio del necesario.

## 5. Tabla Comparativa

| Concepto | Qué ocurre | Por qué importa |
|---|---|---|
| Unión | Mismo bloque compartido por varias interpretaciones. | Útil para ver bytes o valores sin duplicar memoria. |
| Bitfield | Bits compactados dentro de una estructura. | Ideal para flags y estados pequeños. |
| Little-endian | Byte menos significativo primero. | Común en arquitecturas modernas. |
| Big-endian | Byte más significativo primero. | Se observa en arquitecturas y protocolos históricos o específicos. |

## 6. LABORATORIO 
*Como:* estudiante que necesita interpretar datos crudos
*Quiero:* leer un bloque de memoria con distintas perspectivas
*Para:* comprender cómo se guardan y se interpretan valores binarios en hardware y protocolos
*Criterios de Aceptación:*
- [ ] El alumno explica qué hace una unión y por qué comparte memoria.
- [ ] El alumno identifica la diferencia entre endianness y tamaño del tipo.
- [ ] El alumno usa ejemplos de bytes para justificar la lectura del dato.

## 7. PRÁCTICA - Instrucciones para Classroom
En `practica.c`, observa cómo se representan los datos con una unión o bitfield. Imprime los bytes y compara la secuencia esperada para entender el orden de almacenamiento.

```bash
riscv64-unknown-elf-gcc -O0 practica.c -o practica
./practica
```

Checklist de Entregable:
- [ ] Reconocí la diferencia entre interpretar el mismo bloque de memoria de dos formas.
- [ ] Verifiqué el orden de bytes.
- [ ] Expliqué el uso práctico de bitfields y uniones.

## 8. Recursos Visuales
[IMAGEN SUGERIDA: Diagrama de un entero de 32 bits con bytes ordenados según little-endian o big-endian.]

## 9. Pregunta de Cierre 
¿Por qué el mismo conjunto de bytes puede representar valores distintos dependiendo del endianness o de la forma en que se interpreta la memoria, y qué impacto tiene eso en la compatibilidad entre sistemas?
