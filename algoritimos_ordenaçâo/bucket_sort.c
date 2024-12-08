#include <stdio.h>
#include <stdlib.h>

#define BUCKET_COUNT 10

void insertionSort(float arr[], int size) {
    for (int i = 1; i < size; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    if (n <= 0) return;

    float buckets[BUCKET_COUNT][n];
    int bucketCount[BUCKET_COUNT];
    
    for (int i = 0; i < BUCKET_COUNT; i++) {
        bucketCount[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int index = (int)(arr[i] * BUCKET_COUNT);
        if (index == BUCKET_COUNT) {  // Corrigir caso o valor seja 1.0
            index = BUCKET_COUNT - 1;
        }
        buckets[index][bucketCount[index]] = arr[i];
        bucketCount[index]++;
    }

    for (int i = 0; i < BUCKET_COUNT; i++) {
        insertionSort(buckets[i], bucketCount[i]);
    }

    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    float arr[] = {0.42, 0.32, 0.13, 0.55, 0.22, 0.44, 0.65};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Antes da ordenação:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Após a ordenação:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    return 0;
}
