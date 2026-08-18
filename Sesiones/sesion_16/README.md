# Sesión 16: Interrupciones y excepciones

## 1. Objetivo de Aprendizaje
Comprender cómo el sistema responde a eventos externos o condiciones anómalas con interrupciones y excepciones.

## 2. Lectura Guiada 
Una interrupción es como una llamada urgente en una oficina: algo externo ocurre y hay que detener el trabajo momentáneamente para responder. Una excepción es similar, pero suele anunciar que algo salió mal, como una división por cero o una instrucción inválida. El sistema debe guardar el contexto para poder volver después, atender la causa y continuar con el flujo correcto. Esto es un principio clave de la computación moderna: la ejecución no siempre sigue un camino lineal; puede pausarse, atender un evento y luego regresar al punto exacto.

## 3. Temas de la Sesión
- Interrupciones externas y eventos del sistema.
- Excepciones por error o condición inválida.
- Contexto del procesador y restauración.
- Manejadores y flujo de atención.

## 4. Código de Explicación
```c
if (denominador == 0) {
    // excepción de división por cero
}

```

- La operación no puede seguir porque la condición es inválida.
- La CPU o el software debe responder a esa anomalía de forma controlada.

```c
void handler(void) {
    // guardar contexto y atender evento
}

```

- Un manejador normalmente guarda el estado para poder regresar al punto exacto después de tratar el evento.

## 5. Tabla Comparativa

| Concepto | Qué ocurre | Por qué importa |
|---|---|---|
| Interrupción | Evento externo o periódico. | Se atiende sin que el programa termine normalmente. |
| Excepción | Error o condición inválida. | Puede ser recuperable o provocar terminación. |
| Contexto | Estado del procesador y de la ejecución. | Se guarda para restaurar la ejecución posterior. |
| Manejador | Rutina que responde al evento. | Procesa la causa y devuelve el control al flujo normal. |

## 6. LABORATORIO 
*Como:* estudiante de sistemas operativos o embebidos
*Quiero:* ver cómo un sistema responde a eventos externos o errores
*Para:* comprender la necesidad de guardar contexto y volver a la ejecución normal
*Criterios de Aceptación:*
- [ ] El alumno diferencia entre interrupción y excepción.
- [ ] El alumno explica el papel del contexto en la recuperación del flujo.
- [ ] El alumno relaciona la gestión del evento con la CPU y el software.

## 7. PRÁCTICA - Instrucciones para Classroom
En `practica.c`, analiza qué situaciones del programa se parecen a manejo de errores o eventos del sistema. Explica qué parte del código puede considerarse un “evento” y qué haría un manejador.

```bash
riscv64-unknown-elf-gcc -O0 practica.c -o practica
qemu-riscv64 ./practica
```

Checklist de Entregable:
- [ ] Distinguí interrupción de excepción.
- [ ] Explicité el concepto de contexto.
- [ ] Relacioné la respuesta del sistema con la ejecución normal.

## 8. Recursos Visuales
[IMAGEN SUGERIDA: Secuencia de eventos mostrando la CPU ejecutando código normal, una interrupción, la llamada al manejador y el regreso al flujo principal.]

## 9. Pregunta de Cierre 
¿Qué información debe guardarse cuando ocurre un evento inesperado y por qué no es suficiente “saltar” a la rutina de atención sin preservar el estado actual?
