# Sesión 5: Punteros, arrays y aritmética de direcciones

## 1. Objetivo de Aprendizaje
Comprender que un puntero es una dirección y que los arrays se comportan como bloques contiguos de memoria con acceso indexado.

## 2. Lectura Guiada 
Un puntero es como una etiqueta con una dirección. En lugar de guardar un valor, guarda dónde está ese valor. Un array es una fila ordenada de datos contiguos en memoria, como cajas junto a otras cajas. Por eso puedes moverte por el array usando un índice, y también puedes hacerlo sumando una dirección al puntero. Esa idea es central en C: la memoria no es un bloque caótico, sino una secuencia ordenada donde cada elemento ocupa un espacio definido por el tipo.

## 3. Temas de la Sesión
- Punteros y direcciones de memoria.
- Arreglos como bloques contiguos.
- Aritmética de punteros y acceso indexado.
- Relación entre puntero, tipo y desplazamiento.

## 4. Código de Explicación
```c
int arr[4] = {10, 20, 30, 40};
int *p = arr;
printf("%d %d\n", p[0], *(p + 2));

```

- `arr` ocupa una zona contigua de memoria.
- `p` apunta al inicio del arreglo.
- `p[0]` y `*(p + 2)` representan el mismo acceso desde dos formas distintas: índice y dirección.

```c
char *msg = "hola";
printf("%c %c\n", msg[0], *(msg + 1));

```

- Un texto en C se representa como un arreglo de caracteres.
- El puntero avanza byte a byte y el acceso indexado lo recorre de manera natural.

## 5. Tabla Comparativa

| Concepto | Qué ocurre | Por qué importa |
|---|---|---|
| Arreglo | Bloque contiguo de memoria con elementos ordenados. | Permite acceso rápido por índices. |
| Puntero | Dirección a una ubicación de memoria. | Permite recorrer o referenciar datos sin copiar todo. |
| `p[i]` | Equivale a `*(p + i)`. | Forma legible y directa de acceder al contenido. |
| Tipo del puntero | Determina el tamaño del paso al moverse. | Un `char *` avanza 1 byte; un `int *` avanza 4 bytes en RV64. |

## 6. LABORATORIO 
*Como:* estudiante de C que quiere navegar memoria con precisión
*Quiero:* ver cómo un arreglo y un puntero comparten la misma zona de memoria
*Para:* entender la relación entre posición, dirección y acceso a datos en bajo nivel
*Criterios de Aceptación:*
- [ ] El alumno identifica que un arreglo es un bloque contiguo.
- [ ] El alumno explica la diferencia entre `p[i]` y `*(p + i)`.
- [ ] El alumno observa cómo el tipo del puntero cambia el desplazamiento.

## 7. PRÁCTICA - Instrucciones para Classroom
En `practica.c`, identifica cómo se mueve el puntero a través del arreglo y qué hace cada operación. Luego compara la dirección base y la dirección actual para ver el desplazamiento.

```bash
riscv64-unknown-elf-gcc -O0 practica.c -o practica
qemu-riscv64 ./practica
objdump -d ./practica | head
```

Checklist de Entregable:
- [ ] Expresé la relación entre arreglo y puntero.
- [ ] Calculé o observé desplazamientos de memoria.
- [ ] Vinculé la aritmética del puntero con la estructura real del arreglo.

### CRITERIOS DE EVALUACIÓN
Cada práctica vale 100 pts divididos así:
- **Compilación y Ejecución :** Compila con `riscv64-unknown-elf-gcc` sin warnings y corre en `qemu-riscv64`.
- **Visualización de Memoria :** Usa `printf("%p")`, `objdump -h`, `readelf` u otra evidencia; adjunta captura.
- **Comprensión ** Responde la Pregunta de Cierre con sus palabras, indicando DÓNDE vive cada dato y POR QUÉ.
- **Buenas prácticas :** Uso correcto de `free()`, nombres claros, comentarios de dirección y sin leaks.

## 8. Recursos Visuales
[IMAGEN SUGERIDA: Diagrama de un arreglo con índices y un puntero recorriendo cada elemento.]

## 9. Pregunta de Cierre 
¿Por qué un arreglo puede recorrerse con índices o con un puntero, y qué cambia cuando el tipo del puntero es `char *` en lugar de `int *`?
