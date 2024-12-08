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

int exponentialSearch(int arr[], int size, int target) {
    if (arr[0] == target) {
        return 0;
    }

    int bound = 1;
    while (bound < size && arr[bound] <= target) {
        bound *= 2;
    }

    return binarySearch(arr, bound / 2, (bound < size ? bound : size - 1), target);
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Lista ordenada: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nDigite o número que deseja buscar: ");
    scanf("%d", &target);

    int result = exponentialSearch(arr, size, target);

    if (result != -1) {
        printf("Elemento encontrado no índice: %d\n", result);
    } else {
        printf("Elemento não encontrado.\n");
    }

    return 0;
}
