#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mergeSort(char *arr[], int left, int right);
void merge(char *arr[], int left, int mid, int right);

int main() {
    char *arr[] = {"banana", "maçã", "abacaxi", "laranja", "uva"};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    
    printf("Antes da ordenação:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
    
    mergeSort(arr, 0, tamanho - 1);
    
    printf("Após a ordenação:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

void mergeSort(char *arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(char *arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    char **leftArr = (char **)malloc(n1 * sizeof(char *));
    char **rightArr = (char **)malloc(n2 * sizeof(char *));
    
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (strcmp(leftArr[i], rightArr[j]) <= 0) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }
    
    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];
    
    free(leftArr);
    free(rightArr);
}
