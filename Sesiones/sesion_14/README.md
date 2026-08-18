# Sesión 14: Punteros a función y callbacks

## 1. Objetivo de Aprendizaje
Comprender que una función también tiene una dirección y que ese valor puede almacenarse para invocarla indirectamente.

## 2. Lectura Guiada - Método Feynman
Una función no es solo un bloque de instrucciones; también ocupa una dirección de memoria. Cuando guardas un puntero a función, estás guardando “la referencia a ese bloque de código”. Eso permite que el programa decida qué función llamar según la situación, en lugar de estar fijo desde el inicio. En la práctica, eso se usa para callbacks, motores de eventos o lógica configurable. Es un ejemplo claro de que en C el código también puede ser manipulado como dato y no solo los valores.

## 3. Temas de la Sesión
- Dirección de una función.
- Punteros a función y firma.
- Callbacks y lógica indirecta.
- Invocación de funciones por referencia.

## 4. Código de Explicación
```c
int sumar(int a, int b) {
    return a + b;
}

int (*fn)(int, int) = sumar;
int r = fn(2, 3);

```

- `fn` es un puntero a una función con la firma `int(int, int)`.
- Al llamarlo, se ejecuta la función a la que apunta.
- Esto permite decidir en tiempo de ejecución qué operación invocar.

```c
void ejecutar(int (*op)(int, int), int x, int y) {
    printf("%d\n", op(x, y));
}

```

- La función `ejecutar` recibe otra función como argumento.
- Eso permite reutilizar la lógica general y cambiar la operación según el contexto.

## 5. Tabla Comparativa

| Concepto | Qué ocurre | Por qué importa |
|---|---|---|
| Puntero a dato | Apunta a una variable en memoria. | Se usa para leer o modificar datos. |
| Puntero a función | Apunta a un bloque de código. | Permite invocación indirecta. |
| Callback | Función que se pasa como argumento. | Extiende comportamiento sin duplicar lógica. |
| Firma | Tipo de parámetros y retorno. | Es esencial para invocar la función correcta. |

## 6. LABORATORIO - Caso de Usuario / Requisito
*Como:* estudiante de diseño modular
*Quiero:* abstraer operaciones mediante punteros a función
*Para:* crear soluciones más flexibles y reutilizables
*Criterios de Aceptación:*
- [ ] El alumno identifica la diferencia entre puntero a dato y puntero a función.
- [ ] El alumno explica qué es una callback y para qué sirve.
- [ ] El alumno demuestra que la firma de la función es crítica.

## 7. PRÁCTICA - Instrucciones para Classroom
En `practica.c`, revisa si se usan punteros a función o callbacks. Identifica la firma de la función apuntada y explica qué hace la llamada indirecta.

```bash
riscv64-unknown-elf-gcc -O0 practica.c -o practica
qemu-riscv64 ./practica
```

Checklist de Entregable:
- [ ] Identifiqué la firma de la función.
- [ ] Explicité la callback o invocación indirecta.
- [ ] Comparé con una versión no indirecta.

## 8. Recursos Visuales
[IMAGEN SUGERIDA: Diagrama de una función apuntada por un puntero y ejecutada indirectamente desde otra rutina.]

## 9. Pregunta de Cierre (Check de Feynman)
¿Por qué el código también puede tratarse como dato en C, y qué ventajas trae eso para la reutilización y la flexibilidad del programa?
