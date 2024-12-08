#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int binarySearch(char *arr[], int size, char *target);

int main() {
    char *arr[] = {"abacaxi", "banana", "laranja", "maçã", "uva"};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    char *target = "laranja";
    
    qsort(arr, tamanho, sizeof(char *), (int (*)(const void *, const void *))strcmp);
    
    printf("Procurando por: %s\n", target);
    
    int index = binarySearch(arr, tamanho, target);
    
    if (index != -1) {
        printf("Encontrado na posição %d\n", index);
    } else {
        printf("Palavra não encontrada.\n");
    }
    
    return 0;
}

int binarySearch(char *arr[], int size, char *target) {
    int low = 0, high = size - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        int res = strcmp(arr[mid], target);
        
        if (res == 0) return mid;
        if (res < 0) low = mid + 1;
        else high = mid - 1;
    }
    
    return -1;
}
