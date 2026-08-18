# Sesión 4: Macros del preprocesador y constantes

## 1. Objetivo de Aprendizaje
Entender cómo el preprocesador transforma el código antes de la compilación, y cuándo conviene usar macros, `const` y `enum`.

## 2. Lectura Guiada - Método Feynman
El preprocesador es como el ayudante del compilador. Antes de que el compilador haga el trabajo pesado, revisa el código y reemplaza texto según reglas definidas. Las macros son atajos muy poderosos, pero también pueden ser peligrosos si se usan sin cuidado. En cambio, `const` y `enum` representan valores con tipo, lo cual hace el código más seguro y más claro. En bajo nivel, esto importa porque cada valor que defines debe ser consistente, estable y fácil de revisar cuando el programa crece.

## 3. Temas de la Sesión
- Preprocesador y directivas como `#define` e `#include`.
- Macros con y sin parámetros.
- Constantes con `const` y enumeraciones con `enum`.
- Riesgos y beneficios del reemplazo textual.

## 4. Código de Explicación
```c
#define PI 3.1415926535
#define MAX(a, b) ((a) > (b) ? (a) : (b))
const int TAM = 10;

```

- `PI` reemplaza un valor literal por un nombre.
- `MAX` es una macro con parámetro, útil para expresiones reutilizables.
- `const` define una variable inmutable con tipo, más segura que una macro textual.

```c
enum { LED_ROJO = 1, LED_VERDE = 2, LED_AZUL = 4 };
int mask = LED_ROJO | LED_AZUL;

```

- Los `enum` permiten nombrar constantes de forma clara.
- Se usan para representar estados y banderas de manera legible.
- Esto ayuda a evitar valores mágicos en el código.

## 5. Tabla Comparativa

| Concepto | Qué ocurre | Por qué importa |
|---|---|---|
| `#define` | Reemplaza texto antes de compilar. | Útil para valores constantes y expresiones repetitivas. |
| `const` | Declara un valor inmutable con tipo. | Más seguro y más claro en programas grandes. |
| `enum` | Agrupa nombres para valores enteros. | Ideal para flags, estados y opciones. |
| Macro con parámetros | Reemplazo textual con argumentos. | Muy potente, pero puede causar errores si se usa sin cuidado. |

## 6. LABORATORIO
*Como:* desarrollador que quiere mejorar legibilidad y evitar errores
*Quiero:* distinguir entre constantes, macros y variables
*Para:* escribir código más mantenible y más claro en entornos de bajo nivel
*Criterios de Aceptación:*
- [ ] El alumno identifica cuándo conviene usar macro o `const`.
- [ ] El alumno explica la diferencia entre reemplazo textual y dato con tipo.
- [ ] El alumno usa un ejemplo de `enum` o constante simbólica para describir un estado real.

## 7. PRÁCTICA - Instrucciones para Classroom
Revisa el archivo `practica.c` y localiza los valores literales y las macros definidas. Luego transforma esos literales en nombres claros y compara la legibilidad del código.

```bash
riscv64-unknown-elf-gcc -O0 practica.c -o practica
qemu-riscv64 ./practica
```

Checklist de Entregable:
- [ ] Revisé el uso de macros y constantes.
- [ ] Identifiqué cuándo es apropiado usar `#define` o `const`.
- [ ] Explicité por qué la claridad del código afecta mantenimiento y depuración.

### CRITERIOS DE EVALUACIÓN 
Cada práctica vale 100 pts divididos así:
- **Compilación y Ejecución :** Compila con `riscv64-unknown-elf-gcc` sin warnings y corre en `qemu-riscv64`.
- **Visualización de Memora:** Usa `printf("%p")`, `objdump -h`, `readelf` u otra evidencia; adjunta captura.
- **Comprensión :** Responde la Pregunta de Cierre con sus palabras, indicando DÓNDE vive cada dato y POR QUÉ.
- **Buenas prácticas :** Uso correcto de `free()`, nombres claros, comentarios de dirección y sin leaks.

## 8. Recursos Visuales
[IMAGEN SUGERIDA: Diagrama del preprocesador mostrando el archivo fuente antes y después de la sustitución textual.]

## 9. Pregunta de Cierre 
¿Por qué una macro puede ser útil para evitar literales repetidos, pero también puede introducir errores sutiles que una constante con tipo no tiene?
