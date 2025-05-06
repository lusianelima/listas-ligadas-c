#include <stdio.h>
#include <stdlib.h>

// Estrutura de uma célula de uma lista duplamente encadeada
typedef struct Celula {
    int dado;
    struct Celula* prox;
    struct Celula* ant;
} Celula;

// Função para inserir um novo elemento de forma ordenada
void inserirOrdenado(Celula** lista, int valor) {
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->dado = valor;
    nova->prox = NULL;
    nova->ant = NULL;

    if (*lista == NULL || (*lista)->dado >= valor) {
        // Inserção no início da lista
        nova->prox = *lista;
        if (*lista != NULL) {
            (*lista)->ant = nova;
        }
        *lista = nova;
    } else {
        Celula* atual = *lista;
        while (atual->prox != NULL && atual->prox->dado < valor) {
            atual = atual->prox;
        }
        // Inserção após o nó atual
        nova->prox = atual->prox;
        if (atual->prox != NULL) {
            atual->prox->ant = nova;
        }
        atual->prox = nova;
        nova->ant = atual;
    }
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

// Função para liberar a memória da lista
void liberarLista(Celula* lista) {
    Celula* atual = lista;
    while (atual != NULL) {
        Celula* temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

int main() {
    Celula* lista = NULL;

    // Inserindo valores na lista
    inserirOrdenado(&lista, 5);
    inserirOrdenado(&lista, 2);
    inserirOrdenado(&lista, 8);
    inserirOrdenado(&lista, 1);
    inserirOrdenado(&lista, 3);

    // Imprimindo a lista ordenada
    printf("Lista ordenada (dupla): ");
    imprimirLista(lista);

    // Liberando a memória
    liberarLista(lista);
    return 0;
}
