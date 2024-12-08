#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high], i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        quick_sort(arr, low, i);
        quick_sort(arr, i + 2, high);
    }
}

int linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int binary_search(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int size, target, choice_sort, choice_search;

    printf("Informe o tamanho da lista: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < size; i++) arr[i] = rand() % 100;

    printf("\nLista original: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    printf("\nEscolha o algoritmo de ordenação:\n");
    printf("1. Bubble Sort\n");
    printf("2. Quick Sort\n");
    printf("Sua escolha: ");
    scanf("%d", &choice_sort);

    printf("\nEscolha o algoritmo de busca:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("Sua escolha: ");
    scanf("%d", &choice_search);

    clock_t start_time, end_time;
    double time_taken;

    start_time = clock();
    if (choice_sort == 1) {
        printf("\nUsando Bubble Sort...\n");
        bubble_sort(arr, size);
    } else if (choice_sort == 2) {
        printf("\nUsando Quick Sort...\n");
        quick_sort(arr, 0, size - 1);
    }
    end_time = clock();
    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nLista ordenada: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\nTempo de execução da ordenação: %.6f segundos\n", time_taken);

    printf("\nDigite o número que deseja buscar: ");
    scanf("%d", &target);

    start_time = clock();
    int result = -1;
    if (choice_search == 1) {
        printf("\nUsando Linear Search...\n");
        result = linear_search(arr, size, target);
    } else if (choice_search == 2) {
        printf("\nUsando Binary Search...\n");
        result = binary_search(arr, size, target);
    }
    end_time = clock();
    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    if (result != -1) {
        printf("Elemento %d encontrado na posição %d\n", target, result);
    } else {
        printf("Elemento %d não encontrado.\n", target);
    }
    printf("Tempo de execução da busca: %.6f segundos\n", time_taken);

    free(arr);

    return 0;
}
