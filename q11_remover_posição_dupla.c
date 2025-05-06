#include <stdio.h>
#include <stdlib.h>

// Estrutura de uma célula de uma lista duplamente encadeada
typedef struct Celula {
    int dado;
    struct Celula* prox;
    struct Celula* ant;
} Celula;

// Função para remover o i-ésimo item da lista
void removerItem(Celula** lista, int i) {
    if (*lista == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Celula* atual = *lista;

    // Caso a remoção seja do primeiro item
    if (i == 0) {
        *lista = atual->prox;
        if (*lista != NULL) {
            (*lista)->ant = NULL;
        }
        free(atual);
        return;
    }

    // Percorrer até o i-ésimo item
    for (int j = 0; atual != NULL && j < i; j++) {
        atual = atual->prox;
    }

    // Caso o item não exista (índice inválido)
    if (atual == NULL) {
        printf("Índice inválido.\n");
        return;
    }

    // Atualizar os ponteiros dos vizinhos
    if (atual->prox != NULL) {
        atual->prox->ant = atual->ant;
    }
    if (atual->ant != NULL) {
        atual->ant->prox = atual->prox;
    }

    free(atual);
}

// Função para imprimir a lista (do início para o fim)
void imprimirLista(Celula* lista) {
    Celula* atual = lista;
    while (atual != NULL) {
        printf("%d <-> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Função para criar uma nova célula
Celula* novaCelula(int valor) {
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->dado = valor;
    nova->prox = NULL;
    nova->ant = NULL;
    return nova;
}

int main() {
    Celula* lista = novaCelula(1);
    lista->prox = novaCelula(2);
    lista->prox->ant = lista;
    lista->prox->prox = novaCelula(3);
    lista->prox->prox->ant = lista->prox;
    lista->prox->prox->prox = novaCelula(4);
    lista->prox->prox->prox->ant = lista->prox->prox;

    printf("Lista antes de remover: ");
    imprimirLista(lista);

    // Remover o item na posição 2 (terceiro item)
    removerItem(&lista, 2);

    printf("Lista após remover o item na posição 2: ");
    imprimirLista(lista);

    return 0;
}
