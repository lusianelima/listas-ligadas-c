#include <stdio.h>
#include <stdlib.h>

// Definição da célula da lista duplamente encadeada
typedef struct celula {
    int dado;
    struct celula *ant;
    struct celula *prox;
} celula;

// Cria uma nova célula com o valor informado
celula* CriarCelula(int valor) {
    celula *nova = malloc(sizeof(celula));
    nova->dado = valor;
    nova->ant = NULL;
    nova->prox = NULL;
    return nova;
}

// Insere uma nova célula no final da lista
void InserirFim(celula **lista, int valor) {
    celula *nova = CriarCelula(valor);
    if (*lista == NULL) {
        // Lista vazia, nova célula será o primeiro elemento
        *lista = nova;
    } else {
        // Percorre até o final da lista
        celula *atual = *lista;
        while (atual->prox != NULL)
            atual = atual->prox;
        // Liga a nova célula ao final da lista
        atual->prox = nova;
        nova->ant = atual;
    }
}

// Imprime os elementos da lista na ordem direta
void ImprimirLista(celula *lista) {
    while (lista != NULL) {
        printf("%d <-> ", lista->dado);
        lista = lista->prox;
    }
    printf("NULL\n");
}

// Concatena a segunda lista ao final da primeira
void ConcatenarDupla(celula **l1, celula *l2) {
    if (*l1 == NULL) {
        // Se a primeira lista estiver vazia, ela vira a segunda
        *l1 = l2;
        return;
    }

    // Vai até o final da primeira lista
    celula *fim = *l1;
    while (fim->prox != NULL)
        fim = fim->prox;

    // Conecta a segunda lista no final da primeira
    fim->prox = l2;
    if (l2 != NULL)
        l2->ant = fim;
}

int main() {
    celula *lista1 = NULL;
    celula *lista2 = NULL;

    // Preenche a primeira lista com os valores 1, 2, 3
    InserirFim(&lista1, 1);
    InserirFim(&lista1, 2);
    InserirFim(&lista1, 3);

    // Preenche a segunda lista com os valores 4, 5
    InserirFim(&lista2, 4);
    InserirFim(&lista2, 5);

    printf("Lista 1 antes da concatenação:\n");
    ImprimirLista(lista1);

    printf("\nLista 2:\n");
    ImprimirLista(lista2);

    // Concatena lista2 ao final de lista1
    ConcatenarDupla(&lista1, lista2);

    printf("\nLista 1 depois da concatenação:\n");
    ImprimirLista(lista1);

    return 0;
}
