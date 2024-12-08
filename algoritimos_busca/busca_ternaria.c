#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int ternarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == target) {
            return mid1;
        }
        if (arr[mid2] == target) {
            return mid2;
        }

        if (target < arr[mid1]) {
            return ternarySearch(arr, left, mid1 - 1, target);
        } else if (target > arr[mid2]) {
            return ternarySearch(arr, mid2 + 1, right, target);
        } else {
            return ternarySearch(arr, mid1 + 1, mid2 - 1, target);
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Lista ordenada: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nDigite o número que deseja buscar: ");
    scanf("%d", &target);

    int resultTernary = ternarySearch(arr, 0, size - 1, target);
    if (resultTernary != -1) {
        printf("Elemento encontrado com Ternary Search no índice: %d\n", resultTernary);
    } else {
        printf("Elemento não encontrado com Ternary Search.\n");
    }

    int resultBinary = binarySearch(arr, 0, size - 1, target);
    if (resultBinary != -1) {
        printf("Elemento encontrado com Binary Search no índice: %d\n", resultBinary);
    } else {
        printf("Elemento não encontrado com Binary Search.\n");
    }

    return 0;
}
