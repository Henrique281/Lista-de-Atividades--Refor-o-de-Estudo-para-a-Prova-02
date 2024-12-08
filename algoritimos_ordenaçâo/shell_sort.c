#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shellSort(int arr[], int n, int gapSequence[], int gapCount) {
    for (int g = 0; g < gapCount; g++) {
        int gap = gapSequence[g];
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {64, 25, 12, 22, 11};
    int arr2[] = {64, 25, 12, 22, 11};
    int arr3[] = {64, 25, 12, 22, 11};
    
    int n = sizeof(arr1) / sizeof(arr1[0]);
    
    int shell[] = {5, 3, 1};
    int knuth[] = {9, 4, 1};
    int hibbard[] = {7, 3, 1};

    int shellCount = sizeof(shell) / sizeof(shell[0]);
    int knuthCount = sizeof(knuth) / sizeof(knuth[0]);
    int hibbardCount = sizeof(hibbard) / sizeof(hibbard[0]);

    clock_t start, end;

    start = clock();
    shellSort(arr1, n, shell, shellCount);
    end = clock();
    printf("Array ordenado (Shell): ");
    printArray(arr1, n);
    printf("Tempo de execução (Shell): %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    start = clock();
    shellSort(arr2, n, knuth, knuthCount);
    end = clock();
    printf("Array ordenado (Knuth): ");
    printArray(arr2, n);
    printf("Tempo de execução (Knuth): %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    start = clock();
    shellSort(arr3, n, hibbard, hibbardCount);
    end = clock();
    printf("Array ordenado (Hibbard): ");
    printArray(arr3, n);
    printf("Tempo de execução (Hibbard): %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    return 0;
}
