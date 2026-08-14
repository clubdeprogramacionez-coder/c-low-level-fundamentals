# Curso: C Low-Level Fundamentals

Curso de programación de bajo nivel en C centrado en arquitectura de memoria, aritmética de punteros y manipulación de registros a nivel de hardware. Impartido por el Instructor **Enrique Rosas Polo**  y Coinstructor **Darick Yael Gonzalez Mellado**, ambos integrantes del **Club de Programación de ESIME Zacatenco (IPN)**.

## Objetivo del Curso

Comprender el funcionamiento interno del lenguaje C y su interacción directa con la memoria y la CPU. Los alumnos aprenderán a analizar la pila (*stack*), el montón (*heap*), manipular punteros de forma segura y realizar operaciones a nivel de registros y bits.

##  Módulos del Curso

* **`01-memory-layout/`**: Anatomía del proceso en memoria (Stack, Heap, BSS, Data, Text) y asignación dinámica.
* **`02-pointers-and-arrays/`**: Aritmética de punteros, punteros dobles, `void*`, y alineación de datos.
* **`03-registers-and-bit-ops/`**: Operaciones bit a bit (*bitwise ops*), máscaras, palabras de control y simulación de registros de hardware.

## 🛠 Requisitos y Herramientas

Para compilar y analizar los binarios en las prácticas necesitarás:

* **Compilador:** `gcc` o `clang`
* **Depurador:** `gdb`
* **Herramienta de análisis:** `valgrind` (para fugas de memoria)

```bash
# En Linux (Debian/Ubuntu)
sudo apt update && sudo apt install build-essential gdb valgrind
