# Sesión 19: Proyecto integrador

## 1. Objetivo de Aprendizaje
Integrar los conceptos del curso para resolver un problema real con memoria, flujo, tipos y evidencia técnica.

## 2. Lectura Guiada 
A lo largo del curso has visto piezas individuales: tipos, punteros, stack, heap, ABI, assembly y depuración. El proyecto integrador es la etapa donde esas piezas se unen para resolver un problema real. No se trata solo de poner todo junto, sino de tomar decisiones coherentes sobre memoria, organización del programa y flujo de ejecución. Cuando logras explicar por qué una estructura está hecha así, por qué se reserva memoria de determinada forma y por qué el programa responde bien, estás pasando de consumir conocimientos a entender el sistema de verdad.

## 3. Temas de la Sesión
- Integración de tipos, punteros y funciones.
- Gestión de memoria y layout del programa.
- Observación de ejecución y depuración.
- Documentación y evidencia técnica.

## 4. Código de Explicación
```c
struct Registro {
    int id;
    char nombre[16];
};

void mostrar(const struct Registro *r) {
    printf("%d %s\n", r->id, r->nombre);
}

```

- `struct` agrupa datos relacionados en un bloque coherente.
- El puntero permite acceder a esa estructura sin copiarla.
- La función `mostrar` trabaja con una representación clara del dato.

```c
int *datos = malloc(8 * sizeof(int));
if (datos == NULL) {
    return 1;
}
free(datos);

```

- La memoria dinámica existe cuando no se conoce el tamaño al inicio.
- La liberación asegura que el programa no escape memoria ni deje punteros inválidos.

## 5. Tabla Comparativa

| Concepto | Qué ocurre | Por qué importa |
|---|---|---|
| Estructura | Agrupa datos relacionados. | Facilita modelar el problema de forma ordenada. |
| Punteros | Acceso y manipulación de memoria. | Permite compartir y recorrer datos. |
| Memoria | Define la vida y ubicación de cada dato. | Es esencial para la lógica del programa. |
| Depuración | Verifica la solución con evidencia. | Permite corregir errores de flujo y estructura. |

## 6. LABORATORIO 
*Como:* estudiante que consolida el curso
*Quiero:* resolver un problema completo usando los conceptos de bajo nivel vistos durante el curso
*Para:* demostrar dominio de memoria, tipos, flujo, compilación y evidencia técnica
*Criterios de Aceptación:*
- [ ] El proyecto integra al menos tres áreas del curso.
- [ ] El programa compila y ejecuta en RISC-V con QEMU.
- [ ] El alumno documenta la lógica con evidencia y explicación técnica.

## 7. PRÁCTICA - Instrucciones para Classroom
El proyecto final debe reflejar la comprensión del curso: uso de tipos, memoria, punteros, estructura y flujo. Debe compilar con las herramientas del curso y ejecutarse en QEMU. La entrega debe incluir una explicación breve de las decisiones tomadas, los puntos críticos de memoria y la evidencia observada.

```bash
riscv64-unknown-elf-gcc -O0 proyecto.c -o proyecto
qemu-riscv64 ./proyecto
```

Checklist de Entregable:
- [ ] El programa compila sin errores.
- [ ] El programa corre en QEMU.
- [ ] El proyecto integra conceptos de memoria, flujo o tipos.
- [ ] Incluí una explicación de la lógica y la evidencia.

## 8. Recursos Visuales
[IMAGEN SUGERIDA: Diagrama del sistema completo mostrando flujo, memoria, compilación y ejecución del proyecto integrador.]

## 9. Pregunta de Cierre 
¿Cómo se conectan los conceptos de punteros, memoria, control de flujo y compilación para resolver un problema real en lugar de simplemente ejecutar una serie de instrucciones?
