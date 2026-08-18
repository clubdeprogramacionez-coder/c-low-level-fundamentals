# Makefile para Fundamentos de C en Nivel Bajo - RISC-V
# Herramientas y configuración

CC = riscv64-unknown-elf-gcc
OBJDUMP = riscv64-unknown-elf-objdump
GDB = riscv64-unknown-elf-gdb
QEMU = qemu-riscv64

# Flags de compilación
CFLAGS = -march=rv64gc -mabi=lp64 -O0 -Wall -Wextra
CFLAGS_OPT = -march=rv64gc -mabi=lp64 -O2 -Wall -Wextra

# Rutas
SESIONES_DIR = Sesiones
BUILD_DIR = build

# Sesiones disponibles
SESIONES = sesion_01 sesion_02 sesion_03 sesion_04 sesion_05 sesion_06 sesion_07 sesion_08 sesion_09 sesion_10 sesion_11 sesion_12 sesion_13 sesion_14 sesion_15 sesion_16 sesion_17 sesion_18 sesion_19 sesion_20

# Targets por defecto
.PHONY: all clean sesion_% run_% objdump_% asm_%

all: $(addprefix build_,$(SESIONES))

# Template para cada sesión
build_sesion_%:
	@echo "=== Compilando Sesión $* ==="
	@mkdir -p $(BUILD_DIR)/$*
	$(CC) $(CFLAGS) $(SESIONES_DIR)/$*/laboratorio.c -o $(BUILD_DIR)/$*/laboratorio
	$(CC) $(CFLAGS) $(SESIONES_DIR)/$*/practica.c -o $(BUILD_DIR)/$*/practica
	@echo "✓ Compilación exitosa para Sesión $*"

run_sesion_%:
	@echo "=== Ejecutando laboratorio - Sesión $* ==="
	$(QEMU) $(BUILD_DIR)/$*/laboratorio

asm_sesion_%:
	@echo "=== Generando ensamblador - Sesión $* ==="
	$(CC) -S $(CFLAGS) $(SESIONES_DIR)/$*/laboratorio.c -o $(BUILD_DIR)/$*/laboratorio.s
	@echo "Archivo generado: $(BUILD_DIR)/$*/laboratorio.s"

objdump_sesion_%:
	@echo "=== Inspeccionando ELF - Sesión $* ==="
	$(OBJDUMP) -h $(BUILD_DIR)/$*/laboratorio
	@echo ""
	@echo "=== Disassembly (primeras 100 líneas) ==="
	$(OBJDUMP) -d $(BUILD_DIR)/$*/laboratorio | head -100

clean:
	@rm -rf $(BUILD_DIR)
	@echo "✓ Directorio de compilación limpiado"

help:
	@echo "Targets disponibles:"
	@echo "  make all                 - Compilar todas las sesiones"
	@echo "  make run_sesion_0X       - Ejecutar laboratorio de sesión X en QEMU"
	@echo "  make asm_sesion_0X       - Generar ensamblador de sesión X"
	@echo "  make objdump_sesion_0X   - Inspeccionar ELF de sesión X"
	@echo "  make clean               - Limpiar artefactos de compilación"
	@echo ""
	@echo "Ejemplos:"
	@echo "  make build_sesion_01"
	@echo "  make run_sesion_01"
	@echo "  make asm_sesion_02"
