#include <stdio.h>

int interpolationSearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }

        int pos = low + ((double)(high - low) / (arr[high] - arr[low]) * (target - arr[low]));

        if (arr[pos] == target) {
            return pos;
        }

        if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1;
}

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

int main() {
    int uniformArr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int nonUniformArr[] = {5, 15, 35, 70, 120, 250, 400, 600, 1000};
    int sizeUniform = sizeof(uniformArr) / sizeof(uniformArr[0]);
    int sizeNonUniform = sizeof(nonUniformArr) / sizeof(nonUniformArr[0]);
    int target;

    printf("Digite o número que deseja buscar: ");
    scanf("%d", &target);

    printf("\n--- Lista Uniforme ---\n");
    printf("Lista: ");
    for (int i = 0; i < sizeUniform; i++) {
        printf("%d ", uniformArr[i]);
    }
    printf("\n");

    int resultInterpolation = interpolationSearch(uniformArr, sizeUniform, target);
    int resultBinary = binarySearch(uniformArr, 0, sizeUniform - 1, target);

    printf("Interpolation Search: ");
    if (resultInterpolation != -1) {
        printf("Elemento encontrado no índice %d\n", resultInterpolation);
    } else {
        printf("Elemento não encontrado.\n");
    }

    printf("Binary Search: ");
    if (resultBinary != -1) {
        printf("Elemento encontrado no índice %d\n", resultBinary);
    } else {
        printf("Elemento não encontrado.\n");
    }

    printf("\n--- Lista Não Uniforme ---\n");
    printf("Lista: ");
    for (int i = 0; i < sizeNonUniform; i++) {
        printf("%d ", nonUniformArr[i]);
    }
    printf("\n");

    resultInterpolation = interpolationSearch(nonUniformArr, sizeNonUniform, target);
    resultBinary = binarySearch(nonUniformArr, 0, sizeNonUniform - 1, target);

    printf("Interpolation Search: ");
    if (resultInterpolation != -1) {
        printf("Elemento encontrado no índice %d\n", resultInterpolation);
    } else {
        printf("Elemento não encontrado.\n");
    }

    printf("Binary Search: ");
    if (resultBinary != -1) {
        printf("Elemento encontrado no índice %d\n", resultBinary);
    } else {
        printf("Elemento não encontrado.\n");
    }

    return 0;
}
