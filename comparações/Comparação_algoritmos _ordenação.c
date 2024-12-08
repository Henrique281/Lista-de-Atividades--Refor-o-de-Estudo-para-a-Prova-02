#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparacoesBubbleSort = 0;
int comparacoesSelectionSort = 0;
int comparacoesMergeSort = 0;
int comparacoesQuickSort = 0;
int comparacoesBucketSort = 0;

void bubbleSort(int arr[], int tamanho);
void selectionSort(int arr[], int tamanho);
void mergeSort(int arr[], int tamanho);
void quickSort(int arr[], int tamanho);
void bucketSort(int arr[], int tamanho);

void medirTempoExecucao(void (*funcaoOrdenacao)(int[], int), int arr[], int tamanho) {
    clock_t inicio, fim;
    double tempo_cpu_usado;
    
    inicio = clock();
    funcaoOrdenacao(arr, tamanho);
    fim = clock();
    
    tempo_cpu_usado = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f segundos\n", tempo_cpu_usado);
}

void bubbleSort(int arr[], int tamanho) {
    comparacoesBubbleSort = 0;
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            comparacoesBubbleSort++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int tamanho) {
    comparacoesSelectionSort = 0;
    for (int i = 0; i < tamanho - 1; i++) {
        int menorIndice = i;
        for (int j = i + 1; j < tamanho; j++) {
            comparacoesSelectionSort++;
            if (arr[j] < arr[menorIndice]) {
                menorIndice = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[menorIndice];
        arr[menorIndice] = temp;
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        comparacoesMergeSort++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int tamanho) {
    comparacoesMergeSort = 0;
    void mergeSortRecursivo(int arr[], int l, int r) {
        if (l >= r) return;
        int m = l + (r - l) / 2;
        mergeSortRecursivo(arr, l, m);
        mergeSortRecursivo(arr, m + 1, r);
        merge(arr, l, m, r);
    }
    mergeSortRecursivo(arr, 0, tamanho - 1);
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        comparacoesQuickSort++;
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
    return i + 1;
}

void quickSortRecursivo(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortRecursivo(arr, low, pi - 1);
        quickSortRecursivo(arr, pi + 1, high);
    }
}

void quickSort(int arr[], int tamanho) {
    comparacoesQuickSort = 0;
    quickSortRecursivo(arr, 0, tamanho - 1);
}

void bucketSort(int arr[], int tamanho) {
    comparacoesBucketSort = 0;
    int max = arr[0];
    for (int i = 1; i < tamanho; i++) {
        if (arr[i] > max) max = arr[i];
    }
    
    int numBalde = max / 10 + 1;
    int baldes[numBalde][tamanho];
    int tamanhosBalde[numBalde];
    
    for (int i = 0; i < numBalde; i++) {
        tamanhosBalde[i] = 0;
    }
    
    for (int i = 0; i < tamanho; i++) {
        int indice = arr[i] / 10;
        baldes[indice][tamanhosBalde[indice]++] = arr[i];
    }
    
    int indice = 0;
    for (int i = 0; i < numBalde; i++) {
        if (tamanhosBalde[i] > 0) {
            mergeSort(baldes[i], tamanhosBalde[i]);
            for (int j = 0; j < tamanhosBalde[i]; j++) {
                arr[indice++] = baldes[i][j];
            }
        }
    }
}

int main() {
    int arr1[] = {5, 2, 9, 1, 5, 6};
    int tamanho = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("Bubble Sort:\n");
    medirTempoExecucao(bubbleSort, arr1, tamanho);
    printf("Número de comparações: %d\n", comparacoesBubbleSort);
    
    printf("Selection Sort:\n");
    medirTempoExecucao(selectionSort, arr1, tamanho);
    printf("Número de comparações: %d\n", comparacoesSelectionSort);
    
    printf("Merge Sort:\n");
    medirTempoExecucao(mergeSort, arr1, tamanho);
    printf("Número de comparações: %d\n", comparacoesMergeSort);
    
    printf("Quick Sort:\n");
    medirTempoExecucao(quickSort, arr1, tamanho);
    printf("Número de comparações: %d\n", comparacoesQuickSort);
    
    printf("Bucket Sort:\n");
    medirTempoExecucao(bucketSort, arr1, tamanho);
    printf("Número de comparações: %d\n", comparacoesBucketSort);
    
    return 0;
}
