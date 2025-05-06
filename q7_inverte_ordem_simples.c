#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Função para inverter a lista
celula *inverte_lista_simples(celula *l) {
    celula *anterior = NULL;
    celula *atual = l;
    celula *proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;  // Salva o próximo nó
        atual->prox = anterior; // Inverte o ponteiro
        anterior = atual;       // Avança 'anterior'
        atual = proximo;        // Avança 'atual'
    }

    return anterior; // Novo início da lista
}

// Função auxiliar para imprimir a lista
void imprime_lista(celula *l) {
    celula *atual = l;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Função auxiliar para criar uma lista de exemplo
celula *cria_lista_simples() {
    celula *no1 = malloc(sizeof(celula));
    celula *no2 = malloc(sizeof(celula));
    celula *no3 = malloc(sizeof(celula));
    no1->dado = 1; no1->prox = no2;
    no2->dado = 2; no2->prox = no3;
    no3->dado = 3; no3->prox = NULL;
    return no1;
}

int main() {
    celula *lista = cria_lista_simples();
    printf("Original:  ");
    imprime_lista(lista);

    lista = inverte_lista_simples(lista);
    printf("Invertida: ");
    imprime_lista(lista);

    // Liberar memória
    free(lista->prox->prox);
    free(lista->prox);
    free(lista);
    return 0;
}