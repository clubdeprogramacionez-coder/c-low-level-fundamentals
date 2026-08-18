# Sesión 7: Stack, frames y convenciones de llamada

## 1. Objetivo de Aprendizaje
Entender cómo el stack organiza el contexto de ejecución de cada función y por qué las llamadas anidadas necesitan un frame bien definido.

## 2. Lectura Guiada - Método Feynman
Cada vez que llamas a una función, imagina que abres una mesa de trabajo para ese problema. Esa mesa guarda argumentos, variables locales y la dirección de regreso al punto donde se llamó. Eso es el frame. El stack es una pila de estas mesas: cada llamada empuja un nuevo frame y cada retorno lo saca. Si no se organizaran así, la CPU no sabría a dónde volver ni qué datos temporales tenían prioridad. Esa es la razón por la que una llamada de función no es solo una instrucción; es una estructura de memoria y control.

## 3. Temas de la Sesión
- Stack como pila LIFO.
- Frames de función y variables locales.
- Dirección de retorno.
- Convenciones de llamada y contexto de ejecución.

## 4. Código de Explicación
```c
int suma(int a, int b) {
    int c = a + b;
    return c;
}

int main(void) {
    int r = suma(3, 4);
    return r;
}

```

- `a` y `b` son argumentos pasados a la función.
- `c` es una variable local que vive en el frame de `suma`.
- Cuando termina la función, se restaura el contexto y se vuelve al punto de llamada dentro de `main`.

```c
void foo(int x) {
    int y = x * 2;
}

```

- `x` y `y` no son solo nombres; tienen una ubicación lógica durante la ejecución.
- La ABI decide si esos valores se reservarán en registros o en el stack, según el caso.

## 5. Tabla Comparativa

| Concepto | Qué ocurre | Por qué importa |
|---|---|---|
| Stack | Pila de frames de funciones. | Guarda contexto temporal para llamadas anidadas. |
| Frame | Espacio reservado por una función. | Incluye argumentos, locales y dirección de retorno. |
| Dirección de retorno | Punto del programa al que debe volver. | Permite continuar la ejecución después de la llamada. |
| ABI | Regla de uso de registros y stack. | Garantiza que las funciones se comuniquen entre sí de forma consistente. |

## 6. LABORATORIO - Caso de Usuario / Requisito
*Como:* estudiante de bajo nivel
*Quiero:* analizar cómo una llamada de función reserva y libera espacio en el stack
*Para:* comprender por qué las funciones pueden tener variables locales sin romper el flujo del programa
*Criterios de Aceptación:*
- [ ] El alumno identifica el frame de una función y su propósito.
- [ ] El alumno explica qué representa la dirección de retorno.
- [ ] El alumno relaciona el stack con la ejecución de llamadas anidadas.

## 7. PRÁCTICA - Instrucciones para Classroom
Revisa `practica.c` para identificar llamadas y parámetros. Genera el ensamblador sin optimizaciones y busca el uso del stack y de los registros. Luego explica cómo se guarda el contexto y dónde regresa la ejecución.

```bash
riscv64-unknown-elf-gcc -S -O0 practica.c -o practica.s
riscv64-unknown-elf-gcc -O0 practica.c -o practica
qemu-riscv64 ./practica
```

Checklist de Entregable:
- [ ] Revisé el frame de la función.
- [ ] Relacioné la llamada con un stack real.
- [ ] Expliqué el valor de retorno y el punto de regreso.

### CRITERIOS DE EVALUACIÓN - CURSO LOW LEVEL
Cada práctica vale 100 pts divididos así:
- **Compilación y Ejecución (30 pts):** Compila con `riscv64-unknown-elf-gcc` sin warnings y corre en `qemu-riscv64`.
- **Visualización de Memoria (30 pts):** Usa `printf("%p")`, `objdump -h`, `readelf` u otra evidencia; adjunta captura.
- **Comprensión - Feynman (25 pts):** Responde la Pregunta de Cierre con sus palabras, indicando DÓNDE vive cada dato y POR QUÉ.
- **Buenas prácticas (15 pts):** Uso correcto de `free()`, nombres claros, comentarios de dirección y sin leaks.

## 8. Recursos Visuales
[IMAGEN SUGERIDA: Diagrama de la pila con varios frames superpuestos y la dirección de retorno señalada.]

## 9. Pregunta de Cierre (Check de Feynman)
¿Qué ocurre con los datos locales cuando una función llama a otra y por qué la restauración del stack es esencial para que el programa siga funcionando?
