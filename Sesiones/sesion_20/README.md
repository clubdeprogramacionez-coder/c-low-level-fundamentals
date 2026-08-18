# Sesión 20: Presentación final y entrega

## 1. Objetivo de Aprendizaje
Preparar la entrega final del curso, consolidar la evidencia de aprendizaje y comunicar con claridad la solución desarrollada.

## 2. Lectura Guiada 
La entrega final no es solo un programa que corre; es la demostración de que entendiste qué estaba ocurriendo debajo de la superficie. Cuando explicas tu proyecto, no solo hablas del resultado, sino del porqué: por qué elegiste ciertos tipos, cómo gestionaste memoria, cómo se comporta el flujo, qué evidencias corroboran que la solución funciona y qué aprendiste del proceso. Ese es el punto de una presentación técnica: transformar la ejecución en comprensión. Cuando puedes explicarlo con tus propias palabras, ya no estás repitiendo conocimientos; los has integrado.

## 3. Temas de la Sesión
- Evidencia de compilación y ejecución.
- Explicación técnica del proyecto.
- Relación entre memoria, flujo y arquitectura.
- Comunicación de resultados al final del curso.

## 4. Código de Explicación
```c
int main(void) {
    printf("Entrega final\n");
    return 0;
}

```

- El programa final puede ser simple, pero la explicación debe ir más allá del resultado.
- La presentación debe mostrar la intención, el diseño y la evidencia de que la solución es correcta.

```c
printf("%p\n", (void *)&x);
objdump -h ./programa;

```

- La evidencia técnica puede incluir direcciones, layout del binario o secciones del programa.
- Eso convierte la ejecución en una demostración de comprensión y no solo de funcionamiento.

## 5. Tabla Comparativa

| Concepto | Qué ocurre | Por qué importa |
|---|---|---|
| Código | Demuestra la lógica del programa. | Debe explicarse con claridad y no como una caja negra. |
| Ejecución | Prueba que el programa funciona en la máquina. | Requiere evidencia real de compilación y ejecución. |
| Memoria | Confirma la ubicación y el uso de datos. | Explica el comportamiento del sistema. |
| Explicación | Convierte la ejecución en comprensión. | Es el criterio más importante de la entrega final. |

## 6. LABORATORIO -
*Como:* estudiante finalista del curso
*Quiero:* entregar una presentación sólida del trabajo realizado
*Para:* demostrar que no solo compiló sino que entendió y pudo explicar los conceptos de bajo nivel aplicados
*Criterios de Aceptación:*
- [ ] La entrega explica el problema, la solución y la evidencia técnica.
- [ ] La presentación demuestra comprensión de memoria, flujo y arquitectura.
- [ ] El estudiante comunica con claridad la relación entre teoría y ejecución real.

## 7. PRÁCTICA - Instrucciones para Classroom
La actividad final consiste en preparar la explicación y la evidencia que respalde tu trabajo. Debe incluir la compilación exitosa, la ejecución en QEMU, la visualización de memoria o el layout del programa, y una explicación breve de por qué cada decisión del proyecto fue necesaria.

```bash
riscv64-unknown-elf-gcc -O0 proyecto.c -o proyecto
qemu-riscv64 ./proyecto
readelf -S ./proyecto
objdump -h ./proyecto
```

Checklist de Entregable:
- [ ] Compilé y ejecuté el trabajo final.
- [ ] Reuní evidencia de memoria o layout.
- [ ] Expresé la lógica del proyecto con claridad técnica.
- [ ] Presenté la solución como explicación de comprensión y no solo como un archivo que corre.

## 8. Recursos Visuales
[IMAGEN SUGERIDA: Presentación final con diagrama de flujo, memoria, ejecución en QEMU y síntesis de aprendizaje.]

## 9. Pregunta de Cierre 
¿Qué parte de tu proyecto te enseñó más sobre cómo la computadora realmente funciona, y cómo podrías explicárselo a alguien que apenas empieza a aprender C y arquitectura?
