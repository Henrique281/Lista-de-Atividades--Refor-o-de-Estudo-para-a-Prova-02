#include <stdio.h>
#include <stdlib.h>

#define NUM_ALUNOS 10
#define MAX_NOTA 100

typedef struct {
    char nome[50];
    int nota;
} Aluno;

void bucketSort(Aluno alunos[], int n);
int interpolationSearch(Aluno alunos[], int n, int chave);
void insertionSort(Aluno alunos[], int inicio, int fim);

int main() {
    Aluno alunos[NUM_ALUNOS] = {
        {"Alice", 85}, {"Bob", 90}, {"Carlos", 50},
        {"Diana", 77}, {"Eduardo", 93}, {"Fernanda", 61},
        {"Gustavo", 72}, {"Helena", 88}, {"Igor", 64}, {"Júlia", 55}
    };
    
    printf("Antes da ordenação:\n");
    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("%s: %d\n", alunos[i].nome, alunos[i].nota);
    }
    
    bucketSort(alunos, NUM_ALUNOS);
    
    printf("\nApós a ordenação:\n");
    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("%s: %d\n", alunos[i].nome, alunos[i].nota);
    }
    
    int chave;
    printf("\nDigite a nota do aluno que deseja buscar: ");
    scanf("%d", &chave);
    
    int resultado = interpolationSearch(alunos, NUM_ALUNOS, chave);
    if (resultado != -1) {
        printf("Aluno encontrado: %s\n", alunos[resultado].nome);
    } else {
        printf("Aluno com a nota %d não encontrado.\n", chave);
    }

    return 0;
}

void bucketSort(Aluno alunos[], int n) {
    int i, j;
    int maxNota = 0;
    for (i = 0; i < n; i++) {
        if (alunos[i].nota > maxNota) {
            maxNota = alunos[i].nota;
        }
    }

    Aluno **buckets = (Aluno**)malloc((maxNota + 1) * sizeof(Aluno*));
    int *bucketSizes = (int*)malloc((maxNota + 1) * sizeof(int));

    for (i = 0; i <= maxNota; i++) {
        buckets[i] = (Aluno*)malloc(n * sizeof(Aluno));
        bucketSizes[i] = 0;
    }

    for (i = 0; i < n; i++) {
        int index = alunos[i].nota;
        buckets[index][bucketSizes[index]++] = alunos[i];
    }

    int k = 0;
    for (i = 0; i <= maxNota; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], 0, bucketSizes[i] - 1);
            for (j = 0; j < bucketSizes[i]; j++) {
                alunos[k++] = buckets[i][j];
            }
        }
    }

    free(bucketSizes);
    for (i = 0; i <= maxNota; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

int interpolationSearch(Aluno alunos[], int n, int chave) {
    int low = 0, high = n - 1;
    
    while (low <= high && chave >= alunos[low].nota && chave <= alunos[high].nota) {
        if (low == high) {
            if (alunos[low].nota == chave) {
                return low;
            }
            return -1;
        }
        
        int pos = low + ((chave - alunos[low].nota) * (high - low)) / (alunos[high].nota - alunos[low].nota);
        
        if (alunos[pos].nota == chave) {
            return pos;
        }
        
        if (alunos[pos].nota < chave) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    
    return -1;
}

void insertionSort(Aluno alunos[], int inicio, int fim) {
    int i, j;
    Aluno chave;
    for (i = inicio + 1; i <= fim; i++) {
        chave = alunos[i];
        j = i - 1;
        
        while (j >= inicio && alunos[j].nota > chave.nota) {
            alunos[j + 1] = alunos[j];
            j--;
        }
        alunos[j + 1] = chave;
    }
}
