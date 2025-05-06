#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int x;
    struct celula *prox;
} celula;

// Busca ITERATIVA
celula *busca_iterativa(int x, celula *lista) {
    celula *atual = lista;
    while (atual != NULL) {
        if (atual->x == x) {
            return atual; // Encontrou!
        }
        atual = atual->prox;
    }
    return NULL; // Não encontrou
}

// Busca RECURSIVA
celula *busca_recursiva(int x, celula *lista) {
    if (lista == NULL) {
        return NULL; // Caso base: lista vazia
    }
    if (lista->x == x) {
        return lista; // Encontrou!
    }
    return busca_recursiva(x, lista->prox); // Chama para o próximo nó
}

// Função auxiliar para criar uma lista de exemplo
celula *cria_lista_exemplo() {
    celula *no1 = malloc(sizeof(celula));
    celula *no2 = malloc(sizeof(celula));
    celula *no3 = malloc(sizeof(celula));
    no1->x = 10; no1->prox = no2;
    no2->x = 20; no2->prox = no3;
    no3->x = 30; no3->prox = NULL;
    return no1;
}

int main() {
    celula *lista = cria_lista_exemplo();

    // Teste busca iterativa
    celula *resultado_iter = busca_iterativa(20, lista);
    printf("Iterativa: %d\n", resultado_iter ? resultado_iter->x : -1);

    // Teste busca recursiva
    celula *resultado_rec = busca_recursiva(30, lista);
    printf("Recursiva: %d\n", resultado_rec ? resultado_rec->x : -1);

    // Liberar memória
    free(lista->prox->prox);
    free(lista->prox);
    free(lista);
    return 0;
}