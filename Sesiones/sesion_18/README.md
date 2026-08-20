# Sesión 18: Depuración avanzada

## 1. Objetivo de Aprendizaje
Aprender a diagnosticar errores de lógica, flujo y memoria mediante observación de variables, registros y stack.

## 2. Lectura Guiada 
A veces el programa no falla por una instrucción mala, sino por una suposición incorrecta. La depuración es como seguir una pista: revisas el estado del programa en cada paso, observas variables, revisas ramas y confirmas si el problema realmente está ocurriendo donde crees. En bajo nivel, eso se vuelve más preciso porque puedes inspeccionar registros, direcciones y flujo de llamadas. Eso convierte la depuración en una disciplina de observación y evidencia en vez de adivinanza.

## 3. Temas de la Sesión
- Breakpoints y observación del estado.
- Variables, registros y stack.
- Diagnóstico de errores de flujo y punteros.
- Evidencia y reproducibilidad en depuración.

## 4. Código de Explicación
```c
int x = 0;
for (int i = 0; i < 10; i++) {
    x += i;
}
printf("%d\n", x);

```

- Si el valor final no coincide con la expectativa, la depuración debe revisar cada iteración o cada cambio del valor.

```c
int *p = NULL;
printf("%d\n", *p);

```

- La dereferencia de un puntero nulo es un caso clásico que revela la necesidad de inspeccionar memoria y flujo.

## 5. Tabla Comparativa

| Concepto | Qué ocurre | Por qué importa |
|---|---|---|
| Breakpoint | Pausa la ejecución. | Permite inspeccionar el estado en un punto exacto. |
| Stack trace | Muestra la secuencia de llamadas. | Ayuda a localizar el origen del problema. |
| Registro | Estado del procesador. | Muestra cómo se está evaluando el flujo. |
| Variable | Valor actual del dato. | Confirma si la lógica está operando con lo esperado. |

## 6. LABORATORIO 
*Como:* desarrollador que necesita resolver errores complejos
*Quiero:* inspeccionar el estado del programa en tiempo real
*Para:* localizar la causa raíz de fallos de lógica, flujo o memoria
*Criterios de Aceptación:*
- [ ] El alumno usa un breakpoint o un punto de observación para analizar el flujo.
- [ ] El alumno revisa variables y stack para detectar la causa raíz.
- [ ] El alumno documenta el problema y la solución en palabras simples.

## 7. PRÁCTICA - Instrucciones para Classroom
En `practica.c`, identifica puntos donde un valor puede cambiar de forma inesperada, como bucles, condiciones, punteros o llamadas. Usa depuración para observar el estado justo antes y después de esos puntos.

```bash
riscv64-unknown-elf-gcc -O0 practica.c -o practica
qemu-riscv64 ./practica
```

Checklist de Entregable:
- [ ] Analicé al menos un punto crítico de depuración.
- [ ] Revisé variables, flujo y memoria.
- [ ] Explicité la causa del problema con evidencia.

## 8. Recursos Visuales
[IMAGEN SUGERIDA: Captura de depuración con breakpoint, variables y stack mostrando el estado del programa justo antes del fallo.]

## 9. Pregunta de Cierre 
¿Por qué una mala suposición sobre el valor de una variable puede ser más peligrosa que el error visible en la pantalla, y cómo la depuración ayuda a validar esa suposición?
