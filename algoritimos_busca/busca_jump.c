#include <stdio.h>
#include <math.h>

int jumpSearch(int arr[], int size, int target) {
    int step = sqrt(size);
    int prev = 0;

    while (prev < size && arr[prev] < target) {
        prev += step;
        if (prev >= size) {
            return -1;
        }
    }

    for (int i = prev - step; i < prev && i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 4, 7, 9, 12, 14, 16, 18, 20, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Lista ordenada: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nDigite o número que deseja buscar: ");
    scanf("%d", &target);

    int result = jumpSearch(arr, size, target);

    if (result != -1) {
        printf("Elemento encontrado no índice: %d\n", result);
    } else {
        printf("Elemento não encontrado.\n");
    }

    return 0;
}
