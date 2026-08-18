# Sesión 1: Introducción a arquitecturas y modelo de memoria

## 1. Objetivo de Aprendizaje
Comprender cómo un programa en C se transforma en instrucciones ejecutables y cómo esa lógica termina distribuida en memoria en una arquitectura RISC-V.

## 2. Lectura Guiada  
Piensa en la computadora como un taller muy ordenado. La CPU es el trabajador, las instrucciones son los pasos que sigue y la memoria es el almacén donde guarda los materiales. Cuando escribes un programa en C, no estás escribiendo instrucciones de máquina directamente; antes el compilador interpreta tu código y lo transforma en un binario ejecutable. Ese binario no es una masa indiferente: se organiza en secciones como `.text`, `.data`, `.bss`, stack y heap. Si comprendes ese layout, ya no ves C como texto aislado: lo ves como una vista abstracta de la máquina real.

## 3. Temas de la Sesión
- Arquitecturas RISC-V y ejecución de instrucciones.
- Modelo del proceso: texto, datos, stack y heap.
- Compilación cruzada con GCC para RISC-V y ejecución en QEMU.
- Relación entre código fuente, binario y memoria del proceso.

## 4. Código de Explicación
```c
int global_init = 42;
int global_uninit;

int main(void) {
    int local = 7;
    return local + global_init;
}

```

- `global_init` vive en `.data` porque tiene valor inicial.
- `global_uninit` vive en `.bss` porque no tiene valor de inicio.
- `local` vive en el stack porque pertenece al contexto de `main`.
- El `return` no es magia: el compilador genera instrucciones para cargar esos valores, sumarlos y devolver el resultado.

```c
printf("valor = %d\n", global_init);
printf("dir = %p\n", (void *)&global_init);

```

- `printf` muestra el contenido del dato y también la dirección donde vive.
- El contenido es el valor; la dirección es la ubicación lógica de la variable.
- Esa diferencia es la base para entender que cada dato tiene dos facetas: valor y lugar en memoria.

## 5. Tabla Comparativa

| Concepto | Qué ocurre | Por qué importa |
|---|---|---|
| .data vs .bss | .data guarda datos inicializados; .bss guarda datos sin inicialización. | El ejecutable reserva espacio para ambos, pero los trata de manera distinta. |
| Stack vs Heap | Stack es temporal y ligado a llamadas; heap es dinámico y se pide bajo demanda. | La diferencia define la vida útil de cada dato. |
| Variable local vs global | La local vive en el contexto de la función; la global vive con el proceso. | El alcance y la duración cambian según la ubicación. |
| Código vs datos | El código está en `.text`; los datos en `.data`, `.bss`, stack y heap. | La CPU ejecuta instrucciones y también trabaja con valores en memoria. |

## 6. LABORATORIO 
*Como:* estudiante de programación en C
*Quiero:* entender cómo un programa se organiza en memoria y cómo se ejecuta en una arquitectura distinta
*Para:* visualizar la relación entre el código fuente, el binario y la ejecución real del programa
*Criterios de Aceptación:*
- [ ] El alumno identifica al menos dos secciones de memoria en un programa simple.
- [ ] El alumno diferencia entre valor y dirección de una variable.
- [ ] El alumno explica la diferencia entre el código ejecutable y los datos que usa durante la ejecución.

## 7. PRÁCTICA - Instrucciones para Classroom
Abre el archivo `laboratorio.c` y observa cómo se declaran variables globales y locales. Luego compila el programa para RISC-V con GCC cruzado, ejecuta con QEMU y revisa el ELF con `objdump -h` o `readelf -S`.

```bash
riscv64-unknown-elf-gcc -O0 laboratorio.c -o laboratorio
qemu-riscv64 ./laboratorio
riscv64-unknown-elf-objdump -h ./laboratorio
```

Checklist de Entregable:
- [ ] Compilé el programa en RISC-V.
- [ ] Ejecuté el programa en QEMU.
- [ ] Identifiqué secciones relevantes del ELF.
- [ ] Explicué la diferencia entre valor, dirección y ubicación del dato en memoria.

### CRITERIOS DE EVALUACIÓN 
Cada práctica vale 100 pts divididos así:
- **Compilación y Ejecución :** Compila con `riscv64-unknown-elf-gcc` sin warnings y corre en `qemu-riscv64`.
- **Visualización de Memoria :** Usa `printf("%p")`, `objdump -h`, `readelf` u otra evidencia; adjunta captura.
- **Comprensión:** Responde la Pregunta de Cierre con sus palabras, indicando DÓNDE vive cada dato y POR QUÉ.
- **Buenas prácticas :** Uso correcto de `free()`, nombres claros, comentarios de dirección y sin leaks.

## 8. Recursos Visuales
[IMAGEN SUGERIDA: Diagrama del layout de memoria de un proceso mostrando `.text`, `.data`, `.bss`, stack y heap.]

## 9. Pregunta de Cierre 
Si una variable local y otra global tienen valores distintos, ¿por qué no “viven” en el mismo sitio y qué cambia en la forma en que el programa las usa durante la ejecución?
