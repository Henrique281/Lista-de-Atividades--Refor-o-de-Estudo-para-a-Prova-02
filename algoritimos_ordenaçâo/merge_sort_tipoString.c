#include <stdio.h>
#include <string.h>

void merge(char arr[][100], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char L[n1][100], R[n2][100];

    for (int i = 0; i < n1; i++)
        strcpy(L[i], arr[left + i]);
    for (int j = 0; j < n2; j++)
        strcpy(R[j], arr[mid + 1 + j]);

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) {
            strcpy(arr[k], L[i]);
            i++;
        } else {
            strcpy(arr[k], R[j]);
            j++;
        }
        k++;
    }

    while (i < n1) {
        strcpy(arr[k], L[i]);
        i++;
        k++;
    }

    while (j < n2) {
        strcpy(arr[k], R[j]);
        j++;
        k++;
    }
}

void mergeSort(char arr[][100], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    char arr[5][100] = {"banana", "apple", "grape", "orange", "kiwi"};
    int size = 5;

    mergeSort(arr, 0, size - 1);

    printf("Lista ordenada: ");
    for (int i = 0; i < size; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    return 0;
}
