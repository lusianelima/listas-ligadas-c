#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *ant;
    struct celula *prox;
} celula;

// Função para inverter a lista
celula *inverte_lista_dupla(celula *l) {
    celula *temp = NULL;
    celula *atual = l;

    while (atual != NULL) {
        temp = atual->ant;       // Troca os ponteiros 'ant' e 'prox'
        atual->ant = atual->prox;
        atual->prox = temp;
        atual = atual->ant;      // Avança para o próximo nó (antigo 'prox')
    }

    // Ajusta o novo início (último nó da lista original)
    if (temp != NULL) {
        l = temp->ant;
    }
    return l;
}

// Função auxiliar para imprimir a lista
void imprime_lista_dupla(celula *l) {
    celula *atual = l;
    while (atual != NULL) {
        printf("%d <-> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Função auxiliar para criar uma lista de exemplo
celula *cria_lista_dupla() {
    celula *no1 = malloc(sizeof(celula));
    celula *no2 = malloc(sizeof(celula));
    celula *no3 = malloc(sizeof(celula));
    no1->dado = 1; no1->ant = NULL; no1->prox = no2;
    no2->dado = 2; no2->ant = no1; no2->prox = no3;
    no3->dado = 3; no3->ant = no2; no3->prox = NULL;
    return no1;
}

int main() {
    celula *lista = cria_lista_dupla();
    printf("Original:  ");
    imprime_lista_dupla(lista);

    lista = inverte_lista_dupla(lista);
    printf("Invertida: ");
    imprime_lista_dupla(lista);

    // Liberar memória
    free(lista->prox->prox);
    free(lista->prox);
    free(lista);
    return 0;
}