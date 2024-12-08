#include <stdio.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    char isbn[20];
} Livro;

int buscaBinaria(Livro livros[], int n, const char* isbn);

int main() {
    Livro biblioteca[] = {
        {"O Senhor dos Anéis", "J.R.R. Tolkien", "9780261102385"},
        {"Dom Casmurro", "Machado de Assis", "9788526013905"},
        {"Harry Potter e a Pedra Filosofal", "J.K. Rowling", "9780747532699"},
        {"O Pequeno Príncipe", "Antoine de Saint-Exupéry", "9788576650280"},
        {"A Moreninha", "Joaquim Manuel de Macedo", "9788572328483"}
    };
    
    int n = sizeof(biblioteca) / sizeof(biblioteca[0]);
    char isbnBusca[20];

    printf("Digite o ISBN para buscar: ");
    scanf("%s", isbnBusca);

    int indice = buscaBinaria(biblioteca, n, isbnBusca);

    if (indice != -1) {
        printf("Livro encontrado: %s de %s\n", biblioteca[indice].title, biblioteca[indice].author);
    } else {
        printf("Livro não encontrado.\n");
    }

    return 0;
}

int buscaBinaria(Livro livros[], int n, const char* isbn) {
    int baixo = 0;
    int alto = n - 1;
    
    while (baixo <= alto) {
        int meio = (baixo + alto) / 2;
        int cmp = strcmp(livros[meio].isbn, isbn);
        
        if (cmp == 0) {
            return meio;
        } else if (cmp < 0) {
            baixo = meio + 1;
        } else {
            alto = meio - 1;
        }
    }
    
    return -1;
}
