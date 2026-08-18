# Sesión 2: Tipos de Datos y ABI

## 1. Objetivo de Aprendizaje
En esta sesión comprenderás que un tipo en C no es solo una etiqueta: define el tamaño, la representación en memoria y la forma en que la CPU y el compilador lo manejan. Además, verás cómo la ABI de RISC-V define el paso de argumentos entre funciones, el uso de registros y la estructura del stack, para que puedas leer mejor el código generado por el compilador y entender por qué algunos valores viven en registros y otros en memoria.

## 2. Lectura Guiada 
Piensa en la memoria como un edificio con muchos departamentos numerados. Cada variable ocupa uno o varios departamentos, y el compilador decide en qué parte del edificio la guarda. Un `char` es un departamento pequeño; un `int` es más grande; un `double` puede necesitar más espacio porque guarda números con decimales y mayor precisión. Si algo cabe en la mano del trabajador, se guarda en un registro; si no cabe, se deja en un espacio de memoria más grande.

La analogía más útil es esta: los registros son como el escritorio del trabajador, muy rápido y cercano, mientras que la memoria es como el almacén del edificio. Cuando una función recibe argumentos, la ABI dice: “pon estos datos en ciertos registros” o “resérvalos en el stack”. Eso permite que la CPU acceda a ellos con rapidez y de manera consistente, sin importar el compilador exacto.

Cuando ves un programa en C, no debes pensar que las variables “son solo números”. Debes pensar que cada variable tiene una vida concreta: dónde nace, cuánto espacio ocupa, cómo se representa y dónde se encuentra durante la ejecución. La ABI no es un detalle opcional; es la regla que hace que todo funcione de la misma manera en todas las funciones.

## 3. Temas de la Sesión
- Tamaño de los tipos en C y su dependencia de la arquitectura.
- Alineación y representación binaria de los datos en memoria.
- ABI de RISC-V: registros de argumentos, retorno y convención de llamadas.
- Diferencia entre almacenamiento en registros y almacenamiento en memoria (stack y secciones globales).

## 4. Código de Explicación
A continuación se muestran fragmentos representativos de lo que se observa en el laboratorio y en la práctica de esta sesión.

```c
char c = 'A';
short s = 1000;
int i = 100000;
long l = 9999999999L;

printf("char       : %zu bytes\n", sizeof(char));
printf("short      : %zu bytes\n", sizeof(short));
printf("int        : %zu bytes\n", sizeof(int));
printf("long       : %zu bytes\n", sizeof(long));
printf("puntero    : %zu bytes\n", sizeof(void*));
```

Explicación línea por línea:
- `char c = 'A';`: declara una variable de un byte. Sirve para caracteres y ocupa el mínimo espacio posible.
- `short s = 1000;`: es un entero corto. En RISC-V de 64 bits suele ocupar 2 bytes.
- `int i = 100000;`: es un entero estándar. En muchos sistemas de 64 bits sigue ocupando 4 bytes, pero la arquitectura define el tamaño real.
- `long l = 9999999999L;`: es un entero largo, y en RISC-V 64-bit normalmente ocupa 8 bytes.
- `sizeof(char)`: devuelve el tamaño exacto del tipo en bytes. Esto te ayuda a ver que el tamaño no es cualquiera: depende de la arquitectura y la ABI.
- `sizeof(void*)`: un puntero no guarda el valor del dato, sino la dirección donde vive ese dato. En RV64, un puntero suele ocupar 8 bytes.

Lo importante aquí es notar que el compilador no solo “guarda una variable”; el tipo define cuántos bytes necesita y cómo se interpreta el contenido.

```c
uint32_t sumar_u32(uint32_t a, uint32_t b) {
    return a + b;
}

int main(void) {
    uint32_t resultado = sumar_u32(10, 20);
    printf("resultado = %u\n", resultado);
    return 0;
}
```

Explicación línea por línea:
- `uint32_t sumar_u32(uint32_t a, uint32_t b)`: define una función que recibe dos argumentos enteros sin signo de 32 bits.
- `a` y `b` son parámetros. En la ABI de RISC-V, estos se pasan en registros específicos o en el stack, según el tipo y el número de argumentos.
- `return a + b;`: la suma se realiza en el registro o en la instrucción correspondiente. El resultado se devuelve siguiendo la convención de la ABI.
- `uint32_t resultado = sumar_u32(10, 20);`: la llamada a la función usa la convención del sistema para enviar los valores y recibir el resultado.
- `printf(...)`: imprime el valor final, pero la variable ya no vive en la función llamada; su contenido se mueve de regreso según la ABI.

Aquí vemos la conexión directa entre C y la arquitectura: el lenguaje se expresa en términos de tipos y funciones, pero la CPU ejecuta esa lógica usando registros, memoria y convenciones de llamada.

## 5. Tabla Comparativa

| Concepto | C / RISC-V | Qué significa en la práctica |
|---|---|---|
| `char` vs `int` | `char` suele ser 1 byte; `int` normalmente 4 bytes en RV64 | Dos variables del mismo programa pueden ocupar diferente espacio y representar información distinta |
| `.data` vs `.bss` | `.data` guarda datos inicializados; `.bss` guarda datos no inicializados | Las variables globales con valor fijo viven en `.data`; las que comienzan en cero van a `.bss` |
| Stack vs Heap | Stack es de uso temporal y de llamadas; Heap es memoria dinámica | Las variables locales y los argumentos de funciones se gestionan en el stack; la memoria pedida con `malloc` vive en el heap |
| Registro vs Memoria | Registro es acceso rápido y limitado; memoria es más lenta y más grande | Si el dato entra en un registro, la CPU lo usa directamente; si no, se accede con instrucciones de carga/almacenamiento |
| `int` vs `long` | En RV64, `int` suele ser 32 bits y `long` 64 bits | El mismo programa puede procesar valores de distinta longitud y alcance dependiendo del tipo |

## 6. LABORATORIO 
*Como:* Estudiante de programación en C y bajo nivel
*Quiero:* visualizar cómo se almacenan los tipos de datos y cómo la ABI de RISC-V mueve argumentos y resultados entre funciones
*Para:* comprender por qué algunos valores viven en registros y otros en memoria, y cómo eso afecta el comportamiento del programa
*Criterios de Aceptación:*
- [ ] El alumno identifica el tamaño y la representación de al menos 4 tipos distintos en un sistema RISC-V 64-bit.
- [ ] El alumno demuestra que comprende la diferencia entre variables locales, globales y punteros.
- [ ] El alumno relaciona una llamada a función con la ABI de RISC-V y explica dónde se pasan los argumentos y el valor de retorno.
- [ ] El alumno usa evidencia visual (printf, objdump -h, readelf o equivalentemente el ensamblador generado) para respaldar su explicación.

## 7. PRÁCTICA - Instrucciones para Classroom
En el archivo `practica.c` ya existe el punto de partida. Deben revisar el código, identificar qué variables y funciones están modelando el uso de tipos y convención de llamadas, y luego comparar el comportamiento del programa con lo que se observa en el ensamblador generado.

Se recomienda que hagan lo siguiente:
- Observen los tipos declarados (`char`, `short`, `int`, `long`, `float`, `double`, `uint32_t`, `uint64_t`, punteros).
- Verifiquen el tamaño real de cada tipo usando `sizeof` y comparen los resultados esperados en RISC-V 64-bit.
- Analicen cómo se pasan los argumentos de `sumar_u32`, `multiplicar_i64` y `calcular_promedio`.
- Generen el ensamblador con compilación sin optimizaciones para ver dónde aparecen los registros y el stack.
- Relacionen la salida de `printf` con lo que ven en el ensamblador.

Comandos de compilación y ejecución recomendados:

```bash
riscv64-unknown-elf-gcc -S -O0 practica.c -o practica.s
riscv64-unknown-elf-gcc -O0 practica.c -o practica
qemu-riscv64 ./practica
riscv64-unknown-elf-objdump -h ./practica
```

Si quieren profundizar en la memoria del programa:

```bash
readelf -S ./practica
```

La idea no es solo ejecutar el programa, sino explicar por qué el compilador toma decisiones distintas según el tipo y la ABI.

Checklist de Entregable:
- [ ] Compilé el programa con `riscv64-unknown-elf-gcc` sin errores.
- [ ] Ejecuté el programa en QEMU y observé la salida.
- [ ] Generé ensamblador y revisé cómo se manejan los argumentos.
- [ ] Registré evidencia del tamaño de cada tipo y su ubicación conceptual en memoria.
- [ ] Escribí la explicación final de dónde vive cada dato y por qué.

## 8. Recursos Visuales
[IMAGEN SUGERIDA: Diagrama de memoria con secciones .text, .data, .bss, stack y heap, mostrando dónde vive cada tipo y cómo los argumentos se pasan entre funciones]

## 9. Pregunta de Cierre 
Si una función recibe un `int`, un `long` y un `double`, ¿dónde creen que están esos valores antes de entrar a la función, dónde se guardan durante la llamada y por qué la ABI de RISC-V los trata de forma diferente aunque todos sean “datos” para el programa?

Explica tu respuesta con tus propias palabras, sin repetir la definición del libro: habla de ese flujo real en la máquina y de lo que hace el compilador para que la CPU pueda seguir ejecutando instrucciones correctamente.
