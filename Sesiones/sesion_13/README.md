# Sesión 13: Arrays dinámicos y punteros dobles

## 1. Objetivo de Aprendizaje
Entender cómo se crean y gestionan arreglos cuyo tamaño cambia en tiempo de ejecución, y cómo un puntero doble representa estructuras más complejas.

## 2. Lectura Guiada 
Un array dinámico es como un estante que tú ajustas según la cantidad de cosas que vas a guardar. En lugar de fijar el tamaño al inicio, el programa pide memoria cuando la necesita. Un puntero doble añade otra capa: primero apuntas a una lista de punteros, y cada uno de esos punteros apunta a una fila o bloque distinto. Es una estrategia útil cuando quieres matrices más flexibles que no están siempre completamente contiguas en memoria.

## 3. Temas de la Sesión
- Arreglos dinámicos con tamaño variable.
- Punteros dobles y matrices indirectas.
- Reasignación con `realloc`.
- Liberación de estructuras jerárquicas.

## 4. Código de Explicación
```c
int *arr = malloc(n * sizeof(int));
for (int i = 0; i < n; i++) {
    arr[i] = i;
}
free(arr);

```

- El array dinámico ocupa un bloque contiguo y se accede por índice.
- La cantidad de elementos se define en tiempo de ejecución.

```c
int **mat = malloc(filas * sizeof(int *));
for (int i = 0; i < filas; i++) {
    mat[i] = malloc(columnas * sizeof(int));
}

```

- `mat` apunta a una lista de punteros.
- Cada puntero apunta a otra fila con memoria independiente.
- Esto da flexibilidad para representar estructuras con tamaños variables o filas separadas.

## 5. Tabla Comparativa

| Concepto | Qué ocurre | Por qué importa |
|---|---|---|
| Array dinámico | Bloque contiguo con tamaño determinado en tiempo de ejecución. | Acceso por índice y fácil recorrido. |
| Puntero doble | Matriz de punteros. | Permite filas separadas o estructuras jerárquicas. |
| `realloc` | Redimensiona un bloque previo. | Útil cuando la cantidad de datos crece. |
| `free` | Libera memoria asignada. | Evita leaks y punteros colgantes. |

## 6. LABORATORIO
*Como:* estudiante que necesita almacenamiento flexible
*Quiero:* reservar y redimensionar arreglos durante la ejecución
*Para:* manejar colecciones de datos cuyo tamaño no es fijo desde el inicio
*Criterios de Aceptación:*
- [ ] El alumno crea un arreglo dinámico con tamaño calculado en ejecución.
- [ ] El alumno explica la diferencia entre un array y un puntero doble.
- [ ] El alumno maneja correctamente la liberación de cada bloque.

## 7. PRÁCTICA - Instrucciones para Classroom
En `practica.c`, identifica qué parte del código usa arrays dinámicos y qué parte usa punteros dobles. Descríbelo como una estructura de memoria y explica cómo cada elemento es accedido.

```bash
riscv64-unknown-elf-gcc -O0 practica.c -o practica
qemu-riscv64 ./practica
```

Checklist de Entregable:
- [ ] Reservé memoria con tamaño dinámico.
- [ ] Clasifiqué la estructura como array o puntero doble.
- [ ] Verifiqué la liberación final y la integridad de los datos.

## 8. Recursos Visuales
[IMAGEN SUGERIDA: Esquema de un array dinámico contiguo junto a un puntero doble con filas separadas.]

## 9. Pregunta de Cierre 
¿Cuándo es más útil un array dinámico y cuándo un puntero doble, y por qué la forma de acceso a la memoria cambia tanto entre ambos?
