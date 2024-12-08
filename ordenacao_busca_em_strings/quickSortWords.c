#include <stdio.h>
#include <string.h>

void quickSort(char *arr[], int low, int high);
int partition(char *arr[], int low, int high);

int main() {
    char *arr[] = {"banana", "maçã", "abacaxi", "laranja", "uva"};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Antes da ordenação:\n");
    for (int i = 0; i < size; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
    
    quickSort(arr, 0, size - 1);
    
    printf("Após a ordenação:\n");
    for (int i = 0; i < size; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

void quickSort(char *arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(char *arr[], int low, int high) {
    char *pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            char *temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    char *temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return i + 1;
}
