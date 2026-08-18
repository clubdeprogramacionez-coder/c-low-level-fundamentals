#include <stdio.h>
#include <string.h>

/**
 * Sesión 5: Aritmética de Punteros - Práctica
 * 
 * Práctica: Implementar strlen() y strcpy() usando solo punteros
 * 
 * Instrucciones:
 * 1. Implementa mi_strlen() usando punteros (sin indexación)
 * 2. Implementa mi_strcpy() usando punteros
 * 3. Prueba ambas funciones
 * 4. Compila y ejecuta en QEMU
 */

/**
 * mi_strlen: Calcula longitud de cadena usando punteros
 * Recorre hasta encontrar el terminador nulo
 */
int mi_strlen(const char *s) {
    int count = 0;
    while (*s != '\0') {  // Mientras no llegue a terminador nulo
        count++;
        s++;  // Avanza al siguiente carácter
    }
    return count;
}

/**
 * mi_strcpy: Copia cadena usando punteros
 * Copia caracteres hasta encontrar el terminador nulo
 */
char *mi_strcpy(char *dest, const char *src) {
    char *inicio = dest;  // Guardar inicio para retornar
    
    while (*src != '\0') {
        *dest = *src;     // Copiar carácter
        dest++;            // Avanzar destino
        src++;             // Avanzar fuente
    }
    
    *dest = '\0';  // Agregar terminador nulo
    return inicio;
}

int main(void) {
    printf("=== Funciones de Cadena con Punteros ===\n\n");
    
    // Prueba mi_strlen
    const char *msg1 = "Hola";
    const char *msg2 = "RISC-V";
    const char *msg3 = "";
    
    printf("strlen() con punteros:\n");
    printf("strlen(\"%s\") = %d (esperado: %zu)\n", msg1, mi_strlen(msg1), strlen(msg1));
    printf("strlen(\"%s\") = %d (esperado: %zu)\n", msg2, mi_strlen(msg2), strlen(msg2));
    printf("strlen(\"%s\") = %d (esperado: %zu)\n", msg3, mi_strlen(msg3), strlen(msg3));
    
    printf("\n");
    
    // Prueba mi_strcpy
    char buffer[50];
    const char *fuente = "Copiando con punteros";
    
    printf("strcpy() con punteros:\n");
    printf("Fuente: \"%s\"\n", fuente);
    
    mi_strcpy(buffer, fuente);
    printf("Destino después de mi_strcpy(): \"%s\"\n", buffer);
    printf("Verificación con strcmp: %s\n", strcmp(buffer, fuente) == 0 ? "✓ Correcto" : "✗ Error");
    
    printf("\n");
    
    // Múltiples copias
    printf("Múltiples copias:\n");
    const char *strings[] = {"Uno", "Dos", "Tres", "Cuatro"};
    char buffers[4][20];
    
    for (int i = 0; i < 4; i++) {
        mi_strcpy(buffers[i], strings[i]);
        printf("  strings[%d] = \"%s\" → buffers[%d] = \"%s\"\n", 
               i, strings[i], i, buffers[i]);
    }
    
    return 0;
}
