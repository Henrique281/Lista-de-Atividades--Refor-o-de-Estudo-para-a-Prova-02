#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int interpolationSearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]));
        if (arr[pos] == target) return pos;
        if (arr[pos] < target) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int jumpSearch(int arr[], int size, int target) {
    int step = sqrt(size);
    int prev = 0;
    while (prev < size && arr[prev] < target) {
        prev = prev + step;
        if (prev >= size) return -1;
    }
    for (int i = prev - step; i < prev && i < size; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int exponentialSearch(int arr[], int size, int target) {
    if (arr[0] == target) return 0;
    int i = 1;
    while (i < size && arr[i] <= target) i = i * 2;
    return binarySearch(arr + i / 2, fmin(i, size) - i / 2, target);
}

void measureExecutionTime(int (*searchFunc)(int[], int, int), int arr[], int size, int target) {
    clock_t start = clock();
    searchFunc(arr, size, target);
    clock_t end = clock();
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%f ", timeTaken);
}

int main() {
    int sizes[] = {10, 100, 1000, 10000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("| Algoritmo             | Tamanho 10 | Tamanho 100 | Tamanho 1000 | Tamanho 10000 |\n");
    printf("|-----------------------|------------|-------------|--------------|---------------|\n");

    for (int i = 0; i < numSizes; i++) {
        int size = sizes[i];
        int *arr = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            arr[j] = j * 2 + 1;
        }

        printf("| Binary Search         | ");
        measureExecutionTime(binarySearch, arr, size, arr[size / 2]);
        
        printf("| Interpolation Search  | ");
        measureExecutionTime(interpolationSearch, arr, size, arr[size / 2]);
        
        printf("| Jump Search           | ");
        measureExecutionTime(jumpSearch, arr, size, arr[size / 2]);
        
        printf("| Exponential Search    | ");
        measureExecutionTime(exponentialSearch, arr, size, arr[size / 2]);

        free(arr);

        printf("\n");
    }

    return 0;
}
