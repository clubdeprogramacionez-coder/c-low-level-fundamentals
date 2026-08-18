# Sesión 17: Optimización y tamaño de código

## 1. Objetivo de Aprendizaje
Entender cómo el compilador transforma la misma lógica en distintas versiones según el nivel de optimización y por qué eso afecta velocidad, tamaño y legibilidad.

## 2. Lectura Guiada - Método Feynman
El compilador es como un diseñador que convierte tus ideas en un plano para la máquina. Con optimización baja, el plano es más claro y más fácil de seguir; con optimización alta, busca hacer el programa más eficiente en tiempo o en tamaño. Esa diferencia puede cambiar mucho el código generado, el uso de registros y la cantidad de instrucciones. Este tema te ayuda a ver que el mismo programa no siempre se materializa igual: depende de cómo se le pida al compilador que lo convierta.

## 3. Temas de la Sesión
- Niveles de optimización (`-O0`, `-O1`, `-O2`, `-O3`).
- Tamaño del código vs rendimiento.
- Uso de registros y eliminación de trabajo redundante.
- Impacto de la optimización en depuración y legibilidad.

## 4. Código de Explicación
```c
int f(int x) {
    return x * 2;
}

int main(void) {
    return f(10);
}

```

- Con optimización baja, el compilador conserva estructura más clara.
- Con optimización alta, intenta reducir instrucciones y mejorar el flujo del cálculo.

```c
#define SQUARE(x) ((x) * (x))
int y = SQUARE(3);

```

- La lógica puede ser idéntica, pero el compilador decide cómo optimizarla.
- A veces, la optimización cambia la forma en que se ejecuta, aunque no el resultado final.

## 5. Tabla Comparativa

| Concepto | Qué ocurre | Por qué importa |
|---|---|---|
| -O0 | Sin optimización. | Más legible y más fácil de depurar. |
| -O1 | Optimización básica. | Equilibrio entre claridad y rendimiento. |
| -O2 | Optimización más robusta. | Muy común en desarrollo y despliegue. |
| -O3 | Optimización agresiva. | Puede generar código más complejo y menos intuitivo. |

## 6. LABORATORIO - Caso de Usuario / Requisito
*Como:* estudiante de rendimiento y compilación
*Quiero:* comparar cómo cambia el binario según el nivel de optimización
*Para:* entender la relación entre legibilidad, tamaño y velocidad en software de bajo nivel
*Criterios de Aceptación:*
- [ ] El alumno compila con al menos dos niveles de optimización.
- [ ] El alumno compara el tamaño y la estructura del ejecutable.
- [ ] El alumno explica qué beneficio trae la optimización y qué costo puede tener.

## 7. PRÁCTICA - Instrucciones para Classroom
Usa `gcc` con distintos niveles de optimización y compara el size del ejecutable y el ensamblador resultante.

```bash
riscv64-unknown-elf-gcc -O0 laboratorio.c -o lab_o0
riscv64-unknown-elf-gcc -O2 laboratorio.c -o lab_o2
ls -lh lab_o0 lab_o2
objdump -d lab_o0 | head
objdump -d lab_o2 | head
```

Checklist de Entregable:
- [ ] Compilé con más de un nivel de optimización.
- [ ] Comparé tamaño y ensamblador.
- [ ] Explicité el trade-off entre rendimiento y legibilidad.

## 8. Recursos Visuales
[IMAGEN SUGERIDA: Gráfico comparativo de tamaño de binario vs nivel de optimización.]

## 9. Pregunta de Cierre (Check de Feynman)
¿Por qué el mismo programa puede producir binarios distintos según el nivel de optimización, y cómo eso modifica el entendimiento del código y su comportamiento real?
