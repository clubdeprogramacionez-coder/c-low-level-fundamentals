# Sesión 8: ABI y registros de argumentos

## 1. Objetivo de Aprendizaje
Comprender cómo la ABI de RISC-V define el paso de argumentos, el valor de retorno y el uso de registros en una llamada de función.

## 2. Lectura Guiada - Método Feynman
La ABI es el idioma común entre el código C y la CPU. Si una función necesita recibir valores, la ABI dice exactamente dónde deben quedar esos valores para que la función los lea. Es como una regla de entrega entre dos equipos: todos saben dónde poner los paquetes y dónde recogerlos. En RISC-V, los enteros normalmente se pasan por registros, los punteros también y los valores de punto flotante tienen tratamiento distinto. Esa regla hace que todas las funciones se entiendan entre sí y que el compilador genere código compatible.

## 3. Temas de la Sesión
- Concepto de ABI y convención de llamada.
- Registros de argumentos y retorno en RISC-V.
- Paso de enteros, punteros y double.
- Uso del stack cuando los argumentos no caben en registros.

## 4. Código de Explicación
```c
uint32_t suma(uint32_t a, uint32_t b) {
    return a + b;
}

int main(void) {
    return suma(10, 20);
}

```

- Los parámetros `a` y `b` llegan a la función siguiendo la ABI.
- La suma se realiza con esos valores y el resultado regresa usando la convención de retorno.
- La llamada se hace sin que el programador tenga que manejar cada registro a mano; el compilador lo hace por nosotros.

```c
double promedio(double x, double y) {
    return (x + y) / 2.0;
}

```

- Los valores de punto flotante no se gestionan exactamente igual que los enteros.
- La ABI define registros específicos para su paso y retorno, por la diferencia en la representación y el acceso del hardware.

## 5. Tabla Comparativa

| Concepto | Qué ocurre | Por qué importa |
|---|---|---|
| Enteros | Se pasan en registros como `a0`, `a1`, etc. | Permite llamadas rápidas y estandarizadas. |
| Punteros | Se pasan como dirección de memoria. | Se comportan como valores enteros de tamaño preciso. |
| Double/float | Usan registros y convención específicos del FPU. | Distingue la manipulación numérica de la de enteros. |
| Stack | Se usa cuando los argumentos o el contexto lo requieren. | Sirve para casos complejos o cuando no caben en registros. |

## 6. LABORATORIO - Caso de Usuario / Requisito
*Como:* estudiante que quiere interpretar ensamblador con intención
*Quiero:* relacionar parámetros de C con la ABI en RISC-V
*Para:* comprender por qué el código generado por el compilador se ve distinto según el tipo y la cantidad de argumentos
*Criterios de Aceptación:*
- [ ] El alumno explica cómo se pasan los argumentos a una función.
- [ ] El alumno distingue entre enteros y flotantes en la convención de llamada.
- [ ] El alumno usa ensamblador o `objdump` como prueba de su explicación.

## 7. PRÁCTICA - Instrucciones para Classroom
En `practica.c`, identifica las funciones con distintos tipos de argumentos y genera el ensamblador para observar la convención en datos. Luego compara cómo pasan enteros y dobles.

```bash
riscv64-unknown-elf-gcc -S -O0 practica.c -o practica.s
riscv64-unknown-elf-gcc -O0 practica.c -o practica
objdump -d ./practica | head -n 80
```

Checklist de Entregable:
- [ ] Analicé la convención de llamadas en el ensamblador.
- [ ] Comparé tipos enteros y flotantes.
- [ ] Explicité cómo regresan los valores al caller.

## 8. Recursos Visuales
[IMAGEN SUGERIDA: Diagrama de la llamada a una función con argumentos en registros y retorno hacia el punto de llamada.]

## 9. Pregunta de Cierre 
Si una función recibe parámetros enteros y flotantes, ¿por qué la ABI no puede tratarlos todos igual y qué cambia en la CPU cuando el compilador genera el código?
