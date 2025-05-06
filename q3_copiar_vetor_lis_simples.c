#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void CopiarSimples(celula **lista, int v[], int n) {
    celula *atual = *lista;

    // Se a lista já existir, avança até o último nó
    if (atual != NULL) {
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
    }

    // Copia os elementos do vetor para a lista
    for (int i = 0; i < n; i++) {
        celula *novo = malloc(sizeof(celula));
        if (novo == NULL) {
            printf("Erro na alocação de memória!\n");
            exit(1);
        }
        novo->dado = v[i];
        novo->prox = NULL;

        if (atual == NULL) {
            *lista = novo; // Primeiro nó da lista
            atual = *lista;
        } else {
            atual->prox = novo; // Liga ao último nó
            atual = atual->prox;
        }
    }
}

void ImprimirLista(celula *lista) {
    while (lista != NULL) {
        printf("%d -> ", lista->dado);
        lista = lista->prox;
    }
    printf("NULL\n");
}

void LiberarLista(celula *lista) {
    celula *atual = lista;
    while (atual != NULL) {
        celula *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

int main() {
    int vetor[] = {10, 20, 30, 40, 50};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    celula *lista = NULL;

    printf("Copiando vetor para lista...\n");
    CopiarSimples(&lista, vetor, tamanho);

    printf("Lista criada:\n");
    ImprimirLista(lista);

    LiberarLista(lista);
    return 0;
}
