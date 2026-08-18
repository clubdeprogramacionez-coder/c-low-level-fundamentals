# Sesión 12: Memoria dinámica y heap

## 1. Objetivo de Aprendizaje
Entender cómo la memoria dinámica se solicita, se usa y se libera en tiempo de ejecución, y por qué el heap es distinto del stack.

## 2. Lectura Guiada 
El heap es como un almacén de tamaño variable que se usa cuando el programa necesita más memoria de la que la función o la variable local puede manejar por sí misma. `malloc` pide ese espacio; `free` lo devuelve. Esa gestión es explícita y requiere cuidado porque la memoria no desaparece sola. Si se pierde el puntero o se libera dos veces, el programa puede fallar de maneras difíciles de detectar. Por eso la gestión de memoria dinámica es una habilidad esencial: no se trata solo de “guardar cosas”, sino de tener control sobre la vida de esos datos.

## 3. Temas de la Sesión
- Heap como área de memoria dinámica.
- Reserva con `malloc` y `calloc`.
- Liberación con `free`.
- Leaks, punteros colgantes y validación de punteros.

## 4. Código de Explicación
```c
int *p = malloc(sizeof(int) * 5);
if (p == NULL) {
    return 1;
}
for (int i = 0; i < 5; i++) {
    p[i] = i;
}
free(p);

```

- `malloc` reserva un bloque de memoria en el heap.
- Si el sistema no lo puede asignar, devuelve `NULL`.
- `free` libera el bloque cuando ya no se usa.

```c
int *q = malloc(sizeof(int));
free(q);
q = NULL;

```

- Después de liberar, conviene dejar el puntero en `NULL` para evitar uso accidental de memoria ya devuelta.

## 5. Tabla Comparativa

| Concepto | Qué ocurre | Por qué importa |
|---|---|---|
| Stack | Memoria automática y temporal. | Se usa para locales y llamadas de funciones. |
| Heap | Memoria dinámica. | Se pide y se libera a demanda. |
| `malloc` | Reserva un bloque en memoria. | Devuelve un puntero o `NULL` si falla. |
| `free` | Devuelve el bloque al sistema. | Evita leaks y reutilización errónea. |

## 6. LABORATORIO 
*Como:* estudiante que necesita manejar datos cuya vida no está definida por el alcance
*Quiero:* reservar memoria en tiempo de ejecución y liberar correctamente cada bloque
*Para:* prevenir fugas y errores de acceso en programas que requieren memoria dinámica
*Criterios de Aceptación:*
- [ ] El alumno pide memoria con un tamaño correcto.
- [ ] El alumno valida `NULL` antes de usar el puntero.
- [ ] El alumno libera la memoria y explica el impacto de un leak.

## 7. PRÁCTICA - Instrucciones para Classroom
En `practica.c`, identifica las asignaciones dinámicas. Asegúrate de liberar cada bloque que pides y verifica el comportamiento en casos correctos e incorrectos.

```bash
riscv64-unknown-elf-gcc -O0 practica.c -o practica
qemu-riscv64 ./practica
```

Checklist de Entregable:
- [ ] Reservé memoria de forma segura.
- [ ] Liberé correctamente los bloques.
- [ ] Revisé el manejo de errores y punteros nulos.

## 8. Recursos Visuales
[IMAGEN SUGERIDA: Esquema del heap con bloques asignados y liberados en diferentes estados.]

## 9. Pregunta de Cierre 
¿Por qué la memoria dinámica necesita un manejo explícito y qué consecuencias tiene no liberar un bloque cuando el programa ya no lo necesita?
