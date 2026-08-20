# Sesión 10: Estructuras, padding y alineación

## 1. Objetivo de Aprendizaje
Entender por qué una estructura en C no siempre ocupa exactamente la suma de sus campos y por qué la alineación importa en memoria.

## 2. Lectura Guia
Cuando defines una estructura, estás pidiendo al compilador que “ponga juntos” varios elementos. Pero no siempre se mantiene una contigüidad perfecta: a veces se insertan huecos para respetar la alineación. Es como organizar objetos en una estantería: si cada objeto quiere empezar en una posición conveniente, puede quedar espacio vacío entre uno y otro. Ese espacio es el padding. La CPU y la arquitectura prefieren que ciertos tipos comiencen en direcciones alineadas, porque eso facilita el acceso rápido y consistente.

## 3. Temas de la Sesión
- `struct` como bloque de memoria.
- Padding y alineación.
- Impacto del orden de los campos en el tamaño.
- Diseño eficiente de datos en memoria.

## 4. Código de Explicación
```c
struct Persona {
    char inicial;
    int edad;
    double saldo;
};

```

- `char` ocupa 1 byte, pero `int` y `double` suelen requerir alineación.
- El compilador puede insertar bytes vacíos para cumplir la alineación.
- El tamaño final de la estructura puede ser mayor que la suma aparente de los campos.

```c
printf("%zu\n", sizeof(struct Persona));

```

- `sizeof` muestra el tamaño real de la estructura.
- Ese número incluye padding y representa cómo la estructura realmente vive en memoria.

## 5. Tabla Comparativa

| Concepto | Qué ocurre | Por qué importa |
|---|---|---|
| `char` | 1 byte de tamaño. | Alineación simple y liviana. |
| `int` | 4 bytes. | Generalmente exige alineación múltiplo de 4. |
| `double` | 8 bytes. | Suele requerir alineación múltiplo de 8. |
| `struct` | Suma de campos + padding. | Depende del orden y la arquitectura. |

## 6. LABORATORIO 
*Como:* estudiante que diseña estructuras de datos
*Quiero:* entender por qué el tamaño de una `struct` no siempre coincide con la suma de sus campos
*Para:* mejorar el diseño de datos, la eficiencia y la compatibilidad con la arquitectura
*Criterios de Aceptación:*
- [ ] El alumno identifica el efecto del padding en una estructura.
- [ ] El alumno explica por qué la alineación importa.
- [ ] El alumno usa `sizeof` como evidencia del tamaño final del bloque.

## 7. PRÁCTICA - Instrucciones para Classroom
Revisa la estructura en `practica.c` y compara el tamaño esperado con el real usando `sizeof`. Cambia el orden de los campos y observa cómo cambia el tamaño final.

```bash
riscv64-unknown-elf-gcc -O0 practica.c -o practica
./practica
```

Checklist de Entregable:
- [ ] Observé el tamaño real de la estructura.
- [ ] Cambié el orden de los campos y comparé resultados.
- [ ] Explicité cómo el padding afecta la memoria.

## 8. Recursos Visuales
[IMAGEN SUGERIDA: Diagrama de bytes dentro de una estructura mostrando huecos de padding entre campos.]

## 9. Pregunta de Cierre 
¿Por qué dos estructuras con los mismos campos pueden ocupar tamaños distintos según el orden de los miembros, y cómo esto afecta la lectura de memoria y la eficiencia del programa?
