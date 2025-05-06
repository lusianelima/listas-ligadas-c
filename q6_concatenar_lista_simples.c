#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Cria uma nova célula
celula* CriarCelula(int valor) {
    celula *novo = malloc(sizeof(celula));
    novo->dado = valor;
    novo->prox = NULL;
    return novo;
}

// Adiciona um valor ao fim da lista
void InserirFim(celula **lista, int valor) {
    celula *novo = CriarCelula(valor);
    if (*lista == NULL) {
        *lista = novo;
    } else {
        celula *atual = *lista;
        while (atual->prox != NULL)
            atual = atual->prox;
        atual->prox = novo;
    }
}

// Imprime a lista
void ImprimirLista(celula *lista) {
    while (lista != NULL) {
        printf("%d -> ", lista->dado);
        lista = lista->prox;
    }
    printf("NULL\n");
}

// Função para concatenar duas listas encadeadas simples
void ConcatenarSimples(celula **l1, celula *l2) {
    if (*l1 == NULL) {
        *l1 = l2;
        return;
    }

    celula *atual = *l1;
    while (atual->prox != NULL)
        atual = atual->prox;

    atual->prox = l2;
}

//Função principal para testar a concatenação
int main() {
    celula *lista1 = NULL;
    celula *lista2 = NULL;

    // Preenchendo lista1 com 1, 2, 3
    InserirFim(&lista1, 1);
    InserirFim(&lista1, 2);
    InserirFim(&lista1, 3);

    // Preenchendo lista2 com 4, 5
    InserirFim(&lista2, 4);
    InserirFim(&lista2, 5);

    printf("Lista 1 antes da concatenação:\n");
    ImprimirLista(lista1);

    printf("Lista 2:\n");
    ImprimirLista(lista2);

    ConcatenarSimples(&lista1, lista2);

    printf("Lista 1 depois da concatenação:\n");
    ImprimirLista(lista1);

    return 0;
}
