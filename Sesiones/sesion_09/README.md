# Sesión 9: Ensamblador y desensamblado

## 1. Objetivo de Aprendizaje
Aprender a leer código ensamblador generado a partir de C y conectar cada instrucción con la lógica del programa.

## 2. Lectura Guiada 
El código C es una idea humana; el ensamblador es la traducción más cercana a la CPU. Cuando desensamblas un programa, estás viendo cómo la máquina hace cada paso: cargar datos, operar, comparar y saltar. Esa lectura es esencial porque te permite entender que el compilador no hace magia: toma decisiones basadas en la arquitectura y las reglas de la ABI. Una estructura `if`, un ciclo o una suma se materializan como secuencias de instrucciones y registros.

## 3. Temas de la Sesión
- Instrucciones básicas: carga, suma, comparación y salto.
- Desensamblado con `objdump`.
- Relación entre C y assembly.
- Lectura de funciones y flujo de ejecución.

## 4. Código de Explicación
```c
int f(int x) {
    return x + 5;
}

int main(void) {
    return f(10);
}

```

- La función `f` toma un valor y lo suma con 5.
- En assembly, eso se ve como una operación con registros y una instrucción de retorno.
- La llamada `f(10)` no es una magia, sino una convención de paso de argumentos y recuperación del resultado.

```c
int x = 10;
if (x > 5) {
    return 1;
}
return 0;

```

- La condición se vuelve una comparación y luego un salto condicional.
- El flujo del programa cambia según el resultado de esa comparación.

## 5. Tabla Comparativa

| Concepto | Qué ocurre | Por qué importa |
|---|---|---|
| Carga/movimiento | Trae datos o mueve valores entre registros. | Es la base para operar con variables. |
| Aritmética | Suma, resta, comparación y multiplicación. | Materializa la lógica del código C. |
| Saltos | Deciden si se sigue o se cambia el flujo. | Implementan `if`, `while` y `for`. |
| Retorno | Vuelve al punto de llamada. | Completa la ejecución de la función. |

## 6. LABORATORIO 
*Como:* estudiante que quiere ver el código detrás del C
*Quiero:* desensamblar un programa y conectar cada instrucción con la lógica del código fuente
*Para:* entender cómo el compilador transforma decisiones en instrucciones reales
*Criterios de Aceptación:*
- [ ] El alumno distingue instrucciones de cálculo, carga y salto.
- [ ] El alumno conecta una función C con su bloque de assembly.
- [ ] El alumno usa `objdump` como evidencia del proceso de compilación.

## 7. PRÁCTICA - Instrucciones para Classroom
Compila el programa `laboratorio.c` y usa `objdump -d` para inspeccionar el código generado. Busca una función simple, identifica variables, suma o comparación y retorno.

```bash
riscv64-unknown-elf-gcc -O0 laboratorio.c -o laboratorio
objdump -d ./laboratorio | less
```

Checklist de Entregable:
- [ ] Revisé el desensamblado del programa.
- [ ] Relacioné instrucciones con el código C.
- [ ] Explicité cómo el compilador transforma la lógica en assembly.

## 8. Recursos Visuales
[IMAGEN SUGERIDA: Vista del desensamblado con etiquetas, instrucciones y flujo de la función.]

## 9. Pregunta de Cierre 
Si una condición en C genera varios saltos y comparaciones en assembly, ¿qué nos dice eso sobre la forma en que la CPU ejecuta decisiones lógicas?
