#include <stdio.h>
#include <stdint.h>

/**
 * Sesión 5: Aritmética de Punteros y Acceso a Arrays
 * 
 * Laboratorio: Recorrer array usando solo aritmética de punteros
 */

int main(void) {
    int array[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int *p = array;  // Puntero al primer elemento
    
    printf("=== Aritmética de Punteros ===\n\n");
    
    // Información del array
    printf("Array: { ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", array[i]);
    }
    printf("}\n\n");
    
    // Mostrar direcciones y valores usando punteros
    printf("Direcciones y Valores:\n");
    printf("p = &array[0] = %p (valor = %d)\n", (void*)p, *p);
    printf("p+1 = &array[1] = %p (valor = %d)\n", (void*)(p+1), *(p+1));
    printf("p+2 = &array[2] = %p (valor = %d)\n", (void*)(p+2), *(p+2));
    printf("p+7 = &array[7] = %p (valor = %d)\n\n", (void*)(p+7), *(p+7));
    
    // Recorrer array con puntero
    printf("Recorrer array con aritmética de punteros:\n");
    for (int *ptr = array; ptr < array + 8; ptr++) {
        printf("  Dirección: %p, Valor: %d\n", (void*)ptr, *ptr);
    }
    
    printf("\n");
    
    // Equivalencia array[i] == *(array + i)
    printf("Equivalencia array[i] == *(array + i):\n");
    printf("array[3] = %d, *(array + 3) = %d, *(3 + array) = %d\n", 
           array[3], *(array + 3), *(3 + array));
    
    printf("\nEquivalencia array[i] == *(p + i) donde p = &array[0]:\n");
    for (int i = 0; i < 8; i++) {
        printf("array[%d] = %d, *(p + %d) = %d %s\n", 
               i, array[i], i, *(p + i), 
               array[i] == *(p + i) ? "✓" : "✗");
    }
    
    // Diferencia de punteros
    printf("\nDiferencia de Punteros:\n");
    int *pini = array;
    int *pfin = array + 8;
    printf("pfin - pini = %ld (número de elementos)\n", pfin - pini);
    
    return 0;
}
