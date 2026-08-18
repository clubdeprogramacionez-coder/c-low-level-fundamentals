# Programacion de bajo nivel con c: memoria ,punteros y registros

Curso de programación de bajo nivel en C centrado en arquitectura de memoria, aritmética de punteros y manipulación de registros a nivel de hardware. Impartido por el Instructor **Enrique Rosas Polo**  y Coinstructor **Darick Yael Gonzalez Mellado**, ambos integrantes del **Club de Programación de ESIME Zacatenco (IPN)**.

## 📋 Estructura del Curso

- **Sesiones 1-5**: Introducción a arquitectura, tipos de datos, operadores bit a bit, macros y punteros
- **Sesiones 6-10**: Segmentos de memoria, stack, convenciones de llamada, ensamblador, estructuras
- **Sesiones 11-15**: Memoria dinámica, punteros a funciones, registros CSR, MMIO, interrupciones
- **Sesiones 16-20**: Optimizaciones, depuración, proyecto final, presentaciones

## 🚀 Configuración Rápida

### En Codespaces (Recomendado)

1. Abre el repositorio en Codespaces
2. Selecciona la configuración de contenedor `.devcontainer/devcontainer.json`
3. El contenedor instalará automáticamente:
   - Toolchain RISC-V: `riscv64-unknown-elf-gcc`, `objdump`, `gdb`
   - QEMU: `qemu-riscv64` y `qemu-system-riscv64`
   - Herramientas de desarrollo: make, gcc, binutils

### Local (Manual)

```bash
# Ubuntu/Debian
sudo apt-get update
sudo apt-get install -y gcc-riscv64-unknown-elf binutils-riscv64-unknown-elf \
                        gdb-riscv64-unknown-elf qemu-user qemu-system-misc

# macOS (Homebrew)
brew install riscv-tools qemu

# Windows PowerShell (recomendado: usar WSL2 para compatibilidad total)
wsl --install -d Ubuntu
# luego dentro de Ubuntu:
# sudo apt-get update
# sudo apt-get install -y gcc-riscv64-unknown-elf binutils-riscv64-unknown-elf \
#                         gdb-riscv64-unknown-elf qemu-user qemu-system-misc

# Windows PowerShell (instalar QEMU nativo si lo prefieres)
winget install --id QEMU.QEMU -e
# y luego instala el toolchain RISC-V desde una distribución compatible
# (por ejemplo, xPack o un ambiente WSL2/Ubuntu)
```

## ⚙️ Herramientas de Instalación Necesarias

Para trabajar en este curso, necesitas tener instaladas las siguientes herramientas. La mayoría se incluyen automáticamente en Codespaces, pero si trabajas localmente, debes instalarlas manualmente.

### Herramientas Requeridas

#### 1. **Toolchain RISC-V Cross-Compiler**
El compilador cruzado que genera código para arquitectura RISC-V desde tu máquina (que probablemente sea x86/ARM).

**¿Qué incluye?**
- `riscv64-unknown-elf-gcc` - Compilador C/C++ para RISC-V
- `riscv64-unknown-elf-ld` - Enlazador (linker)
- `riscv64-unknown-elf-ar` - Archivador (crear librerías estáticas)
- `riscv64-unknown-elf-objdump` - Inspector de binarios ELF
- `riscv64-unknown-elf-nm` - Listar símbolos
- `riscv64-unknown-elf-size` - Tamaño de segmentos
- `riscv64-unknown-elf-strip` - Eliminar símbolos de depuración

**Instalación:**
```bash
# Ubuntu/Debian
sudo apt-get update
sudo apt-get install -y gcc-riscv64-unknown-elf binutils-riscv64-unknown-elf

# macOS
brew install riscv-tools

# Windows (WSL2/Ubuntu)
wsl --install -d Ubuntu
# dentro de Ubuntu:
sudo apt-get update
sudo apt-get install -y gcc-riscv64-unknown-elf binutils-riscv64-unknown-elf
```

#### 2. **QEMU - Emulador de RISC-V**
Emulador que permite ejecutar programas RISC-V en tu máquina local sin tener un procesador RISC-V físico.

**¿Qué incluye?**
- `qemu-riscv64` - Modo usuario (user-mode): ejecuta aplicaciones RISC-V individuales
- `qemu-system-riscv64` - Modo sistema (system-mode): emula una máquina completa

**Instalación:**
```bash
# Ubuntu/Debian
sudo apt-get install -y qemu-user qemu-system-misc

# macOS
brew install qemu

# Windows (WSL2/Ubuntu)
wsl --install -d Ubuntu
# dentro de Ubuntu:
sudo apt-get install -y qemu-user qemu-system-misc

# Windows (nativo)
winget install --id QEMU.QEMU -e
```

#### 3. **GDB - Depurador de GNU**
Debugger interactivo para inspeccionar y ejecutar programas paso a paso.

**Instalación:**
```bash
# Ubuntu/Debian
sudo apt-get install -y gdb-riscv64-unknown-elf

# macOS
brew install riscv-tools  # Ya incluye GDB

# Windows (WSL2/Ubuntu)
wsl --install -d Ubuntu
# dentro de Ubuntu:
sudo apt-get install -y gdb-riscv64-unknown-elf
```

#### 4. **Make - Automatización de Build**
Herramienta para automatizar compilación usando reglas definidas en `Makefile`.

**Instalación:**
```bash
# Ubuntu/Debian
sudo apt-get install -y build-essential  # Incluye make, gcc, y más

# macOS
brew install make

# Windows (WSL2/Ubuntu)
sudo apt-get install -y build-essential
```

#### 5. **GCC Nativo (Optional, pero recomendado)**
Para compilar herramientas auxiliares en tu máquina anfitriona.

**Instalación:**
```bash
# Ubuntu/Debian
sudo apt-get install -y gcc g++ binutils

# macOS
xcode-select --install  # Instala gcc/clang y herramientas

# Windows (WSL2/Ubuntu)
sudo apt-get install -y build-essential
```

### Verificación de Instalación

Después de instalar, verifica que las herramientas estén disponibles:

```bash
# Compilador RISC-V
riscv64-unknown-elf-gcc --version

# QEMU
qemu-riscv64 --version

# GDB
riscv64-unknown-elf-gdb --version

# Make
make --version
```

Si todos los comandos te muestran versión sin errores, ¡estás listo para el curso!

---

## 📖 Sintaxis Base de C y Fundamentos de Programación

Antes de sumergirte en bajo nivel con RISC-V, es importante dominar la sintaxis fundamental de C. Esta sección cubre los conceptos esenciales que usarás en todo el curso.

### Estructura Básica de un Programa C

```c
#include <stdio.h>      // Incluir bibliotecas

int main() {            // Función principal (punto de entrada)
    printf("Hola Mundo\n");
    return 0;           // Retorna 0 si todo fue bien
}
```

**Notas importantes:**
- `main()` es la función que se ejecuta primero
- `return 0` indica que el programa terminó exitosamente
- Todo programa C debe tener una función `main()`

### Tipos de Datos Fundamentales

C tiene varios tipos básicos para almacenar diferentes tipos de información:

```c
#include <stdint.h>    // Tipos enteros de tamaño fijo (importante en bajo nivel)
#include <stdio.h>

int main() {
    // Enteros
    int edad = 25;                    // Entero estándar (típicamente 32 bits)
    short numero_corto = 100;         // Entero pequeño (16 bits)
    long numero_largo = 1000000;      // Entero grande (64 bits en máquinas modernas)
    unsigned int positivo = 42;       // Solo valores positivos
    
    // Tipos de tamaño fijo (MÁS IMPORTANTE EN BAJO NIVEL)
    uint8_t byte = 255;               // Entero 8 bits (0 a 255)
    int8_t byte_con_signo = -128;     // Entero 8 bits con signo (-128 a 127)
    uint16_t word = 65535;            // Entero 16 bits
    uint32_t dword = 4294967295U;     // Entero 32 bits
    uint64_t qword = 18446744073709551615ULL; // Entero 64 bits
    
    // Punto flotante
    float decimal_32 = 3.14f;         // 32 bits
    double decimal_64 = 3.14159;      // 64 bits
    
    // Carácter
    char letra = 'A';                 // Un carácter (1 byte = 8 bits)
    
    // Booleano (en C99 y posteriores)
    _Bool bandera = 1;                // 1 = verdadero, 0 = falso
    
    return 0;
}
```

**Por qué `stdint.h` es importante:**
- En bajo nivel, necesitas saber exactamente cuántos bits ocupa cada variable
- `int` puede variar según el compilador y arquitectura
- `uint8_t`, `int16_t`, etc. garantizan el tamaño exacto

### Operadores

#### Operadores Aritméticos
```c
int a = 10, b = 3;

int suma = a + b;        // 13
int resta = a - b;       // 7
int producto = a * b;    // 30
int division = a / b;    // 3 (división entera)
int modulo = a % b;      // 1 (residuo)
```

#### Operadores de Comparación (Retornan 0 o 1)
```c
int a = 10, b = 5;

_Bool igual = (a == b);          // 0 (falso)
_Bool diferente = (a != b);      // 1 (verdadero)
_Bool mayor = (a > b);           // 1 (verdadero)
_Bool menor_igual = (a <= b);    // 0 (falso)
```

#### Operadores Lógicos
```c
_Bool resultado1 = 1 && 0;       // AND lógico: 0 (falso)
_Bool resultado2 = 1 || 0;       // OR lógico: 1 (verdadero)
_Bool resultado3 = !1;           // NOT lógico: 0 (falso)
```

#### Operadores Bit a Bit (FUNDAMENTALES EN BAJO NIVEL)
```c
uint8_t a = 0b11110000;  // 240 en decimal, 0xF0 en hex
uint8_t b = 0b10101010;  // 170 en decimal, 0xAA en hex

uint8_t and_result = a & b;     // AND bit a bit: 0b10100000 (160)
uint8_t or_result = a | b;      // OR bit a bit: 0b11111010 (250)
uint8_t xor_result = a ^ b;     // XOR bit a bit: 0b01011010 (90)
uint8_t not_result = ~a;        // NOT bit a bit: 0b00001111 (15)

uint8_t left_shift = a << 1;    // Desplazar izq 1 bit: 0b11100000 (224)
uint8_t right_shift = a >> 2;   // Desplazar der 2 bits: 0b00111100 (60)
```

### Variables, Declaración e Inicialización

```c
// Declaración (reserva memoria pero no inicializa)
int x;                       // x tiene valor indefinido

// Inicialización (declara y asigna valor)
int y = 42;                  // y vale 42

// Múltiples variables del mismo tipo
int a = 1, b = 2, c = 3;

// Declaración en C99+ (importante en el curso)
for (int i = 0; i < 10; i++) {
    // i está disponible solo dentro del bucle
}
```

### Control de Flujo

#### if / else if / else
```c
int edad = 18;

if (edad < 13) {
    printf("Niño\n");
} else if (edad < 18) {
    printf("Adolescente\n");
} else {
    printf("Adulto\n");
}
```

#### Operador Ternario
```c
int edad = 25;
char *categoria = (edad >= 18) ? "Adulto" : "Menor";
```

#### Bucles

**While:**
```c
int i = 0;
while (i < 5) {
    printf("%d\n", i);
    i++;
}
```

**For:**
```c
for (int i = 0; i < 5; i++) {
    printf("%d\n", i);
}
```

**Do-While:**
```c
int i = 0;
do {
    printf("%d\n", i);
    i++;
} while (i < 5);  // Se ejecuta al menos una vez
```

### Arrays (Arreglos)

```c
// Array de 5 enteros
int numeros[5] = {10, 20, 30, 40, 50};

// Acceder a elementos (indexación desde 0)
printf("%d\n", numeros[0]);  // 10
printf("%d\n", numeros[4]);  // 50

// Array de caracteres (string)
char mensaje[20] = "Hola";   // 5 caracteres + '\0' (terminador nulo)

// Recorrer array
for (int i = 0; i < 5; i++) {
    printf("%d\n", numeros[i]);
}
```

### Punteros (CONCEPTO CRÍTICO EN BAJO NIVEL)

Un **puntero** es una variable que almacena la dirección de memoria de otra variable.

```c
int x = 42;              // Variable común
int *ptr = &x;           // Puntero a x (&x = dirección de x)

printf("Valor: %d\n", x);           // 42
printf("Dirección: %p\n", (void*)ptr);  // 0x7fff5fbff8ac (varía)
printf("Valor via puntero: %d\n", *ptr); // 42 (*ptr = desreferenciar)

// Modificar variable a través del puntero
*ptr = 100;
printf("x ahora es: %d\n", x);      // 100
```

**Operadores de punteros:**
- `&variable` - Dirección de variable (operador "dirección de")
- `*puntero` - Valor en la dirección (operador "desreferenciar")

### Funciones

```c
// Declaración (prototipo)
int sumar(int a, int b);

// Definición
int sumar(int a, int b) {
    return a + b;
}

int main() {
    int resultado = sumar(5, 3);  // 8
    printf("Resultado: %d\n", resultado);
    return 0;
}
```

**Funciones sin retorno:**
```c
void saludar(char *nombre) {
    printf("Hola, %s\n", nombre);
}

int main() {
    saludar("Juan");  // Imprime: Hola, Juan
    return 0;
}
```

### Strings (Cadenas de Caracteres)

En C, un string es un array de caracteres terminado con `'\0'` (null terminator).

```c
#include <stdio.h>
#include <string.h>

int main() {
    // Inicialización
    char mensaje[] = "Hola";  // Equivalente: {'H','o','l','a','\0'}
    
    // Longitud
    int len = strlen(mensaje);  // 4
    
    // Copiar
    char copia[20];
    strcpy(copia, mensaje);
    
    // Concatenar
    char texto[30] = "Hola";
    strcat(texto, " Mundo");  // "Hola Mundo"
    
    // Comparar
    if (strcmp(mensaje, "Hola") == 0) {
        printf("Son iguales\n");
    }
    
    return 0;
}
```

### Estructuras (Tipos Personalizados)

```c
// Definir estructura
struct Punto {
    int x;
    int y;
};

int main() {
    // Crear y inicializar
    struct Punto p = {10, 20};
    
    // Acceder a miembros
    printf("X: %d, Y: %d\n", p.x, p.y);
    
    // Array de estructuras
    struct Punto puntos[3] = {
        {0, 0},
        {10, 20},
        {30, 40}
    };
    
    return 0;
}
```

### Entrada/Salida (I/O)

```c
#include <stdio.h>

int main() {
    // Salida
    printf("Hola\n");
    printf("Número: %d\n", 42);
    printf("Punto flotante: %.2f\n", 3.14159);  // 3.14
    
    // Entrada
    int numero;
    printf("Ingresa un número: ");
    scanf("%d", &numero);  // Nota: usamos & para puntero
    
    printf("Ingresaste: %d\n", numero);
    
    return 0;
}
```

**Especificadores de formato comunes:**
- `%d` - Entero decimal
- `%x` - Entero hexadecimal
- `%o` - Entero octal
- `%f` - Punto flotante
- `%c` - Carácter
- `%s` - String
- `%p` - Puntero (dirección de memoria)

### Macros del Preprocesador

```c
#include <stdio.h>

// Constante simbólica
#define MAX_SIZE 100

// Macro con parámetros
#define DOBLE(x) ((x) * 2)

// Compilación condicional
#define DEBUG 1

int main() {
    int array[MAX_SIZE];
    
    int resultado = DOBLE(5);  // Expande a: ((5) * 2) = 10
    
#ifdef DEBUG
    printf("Modo debug activado\n");
#endif
    
    return 0;
}
```

### Comentarios

```c
// Comentario de una línea

/*
 * Comentario de múltiples líneas
 * Muy útil para explicar bloques de código
 */
```

### Convenciones y Buenas Prácticas

1. **Nombres descriptivos:**
   ```c
   int edad_usuario = 25;      // ✓ Bueno: claro qué representa
   int a = 25;                 // ✗ Malo: ambiguo
   ```

2. **Tipos de tamaño fijo en bajo nivel:**
   ```c
   #include <stdint.h>
   uint8_t registro_hw = 0xFF;  // ✓ Exactamente 8 bits
   unsigned char byte = 0xFF;   // ✗ Puede variar según arquitectura
   ```

3. **Inicializar variables:**
   ```c
   int x = 0;                   // ✓ Inicializado
   int y;                       // ✗ Valor indefinido
   ```

4. **Usar constantes para valores mágicos:**
   ```c
   #define BITS_POR_BYTE 8       // ✓ Código legible
   int bits = valor * 8;        // ✗ ¿De dónde sale el 8?
   ```

5. **Espaciado y sangría consistentes:**
   ```c
   // ✓ Código legible
   if (x > 0) {
       printf("Positivo\n");
   }
   
   // ✗ Difícil de leer
   if(x>0)printf("Positivo\n");
   ```

### Próximos Pasos

Domina estos conceptos fundamentales antes de pasar a las sesiones. Cada sesión del curso construye sobre estos cimientos, agregando complejidad con:
- Manipulación de memoria
- Convenciones de llamada
- Ensamblador RISC-V
- Hardware acceso
- Interrupciones

---

## 📁 Estructura de Carpetas

```
c-low-level-fundamentals/
├── .devcontainer/
│   └── devcontainer.json          # Configuración del contenedor
├── .vscode/
│   ├── tasks.json                 # Tareas de compilación y ejecución
│   └── launch.json                # Configuración de depuración
├── Makefile                       # Build automation
├── README.md                      # Este archivo
└── Sesiones/
    ├── sesion_01/                 # Arquitecturas y modelo de memoria
    ├── sesion_02/                 # Tipos, alineación y registros
    ├── sesion_03/                 # Operadores bit a bit
    ├── sesion_04/                 # Macros del preprocesador
    ├── sesion_05/                 # Aritmética de punteros y arrays
    ├── sesion_06/                 # Segmentos y layout de memoria
    ├── sesion_07/                 # Stack y convenciones de llamada
    ├── sesion_08/                 # ABI y registros de argumentos
    ├── sesion_09/                 # Ensamblador y desensamblado
    ├── sesion_10/                 # Estructuras, padding y alineación
    ├── sesion_11/                 # Uniones, bitfields y endianness
    ├── sesion_12/                 # Memoria dinámica
    ├── sesion_13/                 # Arrays dinámicos y punteros dobles
    ├── sesion_14/                 # Punteros a función y callbacks
    ├── sesion_15/                 # CSR, MMIO y acceso a hardware
    ├── sesion_16/                 # Interrupciones y excepciones
    ├── sesion_17/                 # Optimización y tamaño de código
    ├── sesion_18/                 # Depuración avanzada
    ├── sesion_19/                 # Proyecto integrador
    └── sesion_20/                 # Presentación final y entrega
```

Cada sesión contiene:
- `laboratorio.c` - Ejercicio práctico con código de ejemplo
- `practica.c` - Código base para los estudiantes
- `README.md` - Teoría, conceptos clave y guía de trabajo

## 🔧 Uso Rápido

### Compilar todas las sesiones
```bash
make all
```

### Compilar una sesión específica
```bash
make build_sesion_01
```

### Ejecutar laboratorio en QEMU
```bash
make run_sesion_01
```

### Generar ensamblador RISC-V
```bash
make asm_sesion_02
```

### Inspeccionar estructura ELF
```bash
make objdump_sesion_01
```

## 📚 Contenido por Sesión

### Sesión 1: Introducción a Arquitecturas y Modelo de Memoria
- **Conceptos**: Von Neumann vs Harvard, CISC vs RISC, ISA RISC-V (rv64gc), segmentos de proceso
- **Lab**: Cross-compile "Hola Mundo", ejecutar en QEMU, inspeccionar con objdump
- **Herramientas**: `gcc`, `objdump -h`, `qemu-riscv64`

### Sesión 2: Tipos de Datos y Mapeo a Registros RISC-V
- **Conceptos**: stdint.h, tamaño y alineación, registros x0-x31, ABI RISC-V
- **Lab**: Declarar variables y generar assembly para ver asignación de registros
- **Herramientas**: `gcc -S -O0`, análisis de .s

### Sesión 3: Operadores Bit a Bit
- **Conceptos**: AND, OR, XOR, NOT, desplazamientos, máscaras, set/clear/toggle/check bit
- **Lab**: Simular registro GPIO de 8 bits con funciones de manipulación
- **Herramientas**: `gcc`, `qemu-riscv64`

### Sesión 4: Macros del Preprocesador
- **Conceptos**: #define, #ifdef, macros constantes, buenas prácticas
- **Lab**: Crear hardware.h con macros de manipulación, ver expansión con -E
- **Herramientas**: `gcc -E`, análisis de preprocesador

### Sesión 5: Aritmética de Punteros y Arrays
- **Conceptos**: *, &, equivalencia arrays ↔ punteros, incremento según tipo
- **Lab**: Recorrer array con aritmética de punteros, imprimir direcciones
- **Herramientas**: `gcc`, `printf %p`, `qemu-riscv64`

## 🛠️ Comandos Comunes

```bash
# Compilar con cross-compiler RISC-V
riscv64-unknown-elf-gcc -march=rv64gc -mabi=lp64 -O0 archivo.c -o ejecutable

# Ejecutar en emulador RISC-V
qemu-riscv64 ./ejecutable

# Generar código ensamblador
riscv64-unknown-elf-gcc -S -O0 archivo.c -o archivo.s

# Inspeccionar estructura ELF
riscv64-unknown-elf-objdump -h ejecutable

# Ver ensamblador completo
riscv64-unknown-elf-objdump -d ejecutable

# Símbolos de la aplicación
riscv64-unknown-elf-nm ejecutable

# Tamaño de segmentos
riscv64-unknown-elf-size ejecutable

# Depuración remota (terminal 1)
qemu-riscv64 -g 1234 ./ejecutable

# Depuración remota (terminal 2)
riscv64-unknown-elf-gdb ./ejecutable -ex "target remote :1234"
```

## 📖 Referencias

- [RISC-V ISA Spec](https://riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf)
- [RISC-V ABI Spec](https://github.com/riscv/riscv-elf-psabi-doc)
- [QEMU RISC-V](https://www.qemu.org/docs/master/system/target-riscv.html)
- [Cortex-M Assembly Guide](https://developer.arm.com/documentation/dui0073/a/arm-instruction-summary)

## 📝 Notas Importantes

1. **Endianness**: RISC-V es por defecto little-endian
2. **Convención de Llamadas**: a0-a7 para argumentos, ra para retorno, sp para stack pointer
3. **Segmentos**: .text (código), .data (inicializados), .bss (no inicializados), .rodata (constantes)
4. **Stack Growth**: Crece hacia direcciones bajas (sp decrece)

## 🤝 Contribuidores

- Instructor: Enrique Rosas Polo
- Coordinacion de formacion tecnica: Darick Yael Gonzalez Mellado
- Estudiantes del curso Progamacion de bajo nivel con c: memoria, punteros y registros 2027-1
## 📄 Licencia

MIT - Libre para uso educativo

------------
