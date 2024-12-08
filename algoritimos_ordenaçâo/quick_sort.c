#include <stdio.h>

void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int arr[], int baixo, int alto, int tipoPivo) {
    int pivo;
    switch(tipoPivo) {
        case 1:
            pivo = arr[baixo];
            break;
        case 2:
            pivo = arr[alto];
            break;
        case 3:
            pivo = arr[(baixo + alto) / 2];
            break;
        default:
            pivo = arr[baixo];
            break;
    }

    int i = baixo - 1;
    for (int j = baixo; j < alto; j++) {
        if (arr[j] <= pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }

    trocar(&arr[i + 1], &arr[alto]);
    return i + 1;
}

void quickSort(int arr[], int baixo, int alto, int tipoPivo) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto, tipoPivo);
        quickSort(arr, baixo, pi - 1, tipoPivo);
        quickSort(arr, pi + 1, alto, tipoPivo);
    }
}

void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    imprimirArray(arr, tamanho);

    printf("\nOrdenando com o primeiro elemento como pivô:\n");
    quickSort(arr, 0, tamanho - 1, 1);
    imprimirArray(arr, tamanho);

    int arr2[] = {10, 7, 8, 9, 1, 5};
    printf("\nOrdenando com o último elemento como pivô:\n");
    quickSort(arr2, 0, tamanho - 1, 2);
    imprimirArray(arr2, tamanho);

    int arr3[] = {10, 7, 8, 9, 1, 5};
    printf("\nOrdenando com o elemento do meio como pivô:\n");
    quickSort(arr3, 0, tamanho - 1, 3);
    imprimirArray(arr3, tamanho);

    return 0;
}
