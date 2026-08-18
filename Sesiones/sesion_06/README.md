# Sesión 6: Segmentos de memoria y layout del proceso

## 1. Objetivo de Aprendizaje
Conocer cómo se organiza un proceso en memoria y por qué cada sección tiene un propósito distinto durante la ejecución.

## 2. Lectura Guiada 
Un proceso es como una casa con habitaciones claramente definidas. La parte del código es la sala de trabajo principal; los datos inicializados son los materiales listos para usar; los datos no inicializados son espacios reservados para cuando se necesiten; el stack es la mesa de trabajo temporal y el heap es el almacén flexible. Cada zona tiene una función y una vida útil distinta. Si entiendes ese layout, entiendes por qué un programa puede comportarse de manera diferente según dónde se almacena cada variable y cómo se gestiona la memoria.

## 3. Temas de la Sesión
- Secciones `.text`, `.data`, `.bss`, stack y heap.
- Layout del proceso como estructura lógica.
- Diferencia entre variables globales, locales y dinámicas.
- Errores comunes de memoria y alcance.

## 4. Código de Explicación
```c
int global_init = 7;
int global_uninit;

int main(void) {
    int local = 9;
    return local;
}

```

- `global_init` vive en `.data` porque tiene valor inicial.
- `global_uninit` vive en `.bss` porque comienza con cero y no se inicializa explícitamente.
- `local` vive en el stack porque pertenece a la función `main`.

```c
char *p = malloc(32);
free(p);

```

- `malloc` reserva memoria dinámica dentro del heap.
- Esa memoria no está ligada al alcance de una función; tiene que gestionarse explícitamente.
- `free` devuelve ese bloque al sistema cuando ya no se necesita.

## 5. Tabla Comparativa

| Concepto | Qué ocurre | Por qué importa |
|---|---|---|
| .text | Sección donde vive el código ejecutable. | La CPU lee instrucciones desde aquí para ejecutar el programa. |
| .data | Variables globales inicializadas. | Tienen un valor definido desde el inicio. |
| .bss | Variables globales no inicializadas. | Se reserva espacio y se inicializan como cero. |
| Stack | Variables locales y contexto de llamadas. | Se usa para trabajo temporal en ejecución. |
| Heap | Memoria dinámica. | Se pide y se libera explícitamente con funciones del sistema. |

## 6. LABORATORIO
*Como:* estudiante que necesita entender la organización del proceso
*Quiero:* distinguir dónde vive cada tipo de dato y qué parte del proceso lo administra
*Para:* interpretar correctamente errores de memoria y el layout de un programa
*Criterios de Aceptación:*
- [ ] El alumno identifica al menos cinco zonas o secciones de memoria.
- [ ] El alumno explica la diferencia entre dato global, local y dinámico.
- [ ] El alumno usa `readelf` o `objdump` como evidencia visual del layout.

## 7. PRÁCTICA - Instrucciones para Classroom
Revisa `practica.c` y clasifica cada variable según su zona de almacenamiento. Luego compila el programa y usa `readelf -S` o `objdump -h` para comparar el código fuente con el binario resultante.

```bash
riscv64-unknown-elf-gcc -O0 practica.c -o practica
readelf -S ./practica
objdump -h ./practica
```

Checklist de Entregable:
- [ ] Clasifiqué todas las variables según su ubicación.
- [ ] Revisé el layout del ejecutable con `readelf` o `objdump`.
- [ ] Expliqué por qué cada zona tiene un propósito distinto.

### CRITERIOS DE EVALUACIÓN 
Cada práctica vale 100 pts divididos así:
- **Compilación y Ejecución :** Compila con `riscv64-unknown-elf-gcc` sin warnings y corre en `qemu-riscv64`.
- **Visualización de Memoria :** Usa `printf("%p")`, `objdump -h`, `readelf` u otra evidencia; adjunta captura.
- **Comprensión :** Responde la Pregunta de Cierre con sus palabras, indicando DÓNDE vive cada dato y POR QUÉ.
- **Buenas prácticas :** Uso correcto de `free()`, nombres claros, comentarios de dirección y sin leaks.

## 8. Recursos Visuales
[IMAGEN SUGERIDA: Diagrama del layout de un proceso con secciones `.text`, `.data`, `.bss`, stack y heap.]

## 9. Pregunta de Cierre (Check de Feynman)
¿Por qué una variable local no se comporta igual que una global si ambas almacenan datos, y por qué el stack y el heap no son intercambiables aunque ambos son memoria?
