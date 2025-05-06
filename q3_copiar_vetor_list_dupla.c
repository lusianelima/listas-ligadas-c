#include <stdio.h>
#include <stdlib.h>

// Estrutura da célula da lista duplamente encadeada
typedef struct celulaD {
    int dado;
    struct celulaD *ant;
    struct celulaD *prox;
} celulaD;

// Função para copiar vetor para lista duplamente encadeada
void CopiarDupla(celulaD **lista, int v[], int n) {
    celulaD *atual = *lista;
    celulaD *ultimo = NULL;

    // Se a lista já existir, vai até o último nó
    if (atual != NULL) {
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        ultimo = atual;
    }

    // Copia os elementos do vetor para a lista
    for (int i = 0; i < n; i++) {
        celulaD *novo = malloc(sizeof(celulaD));
        if (novo == NULL) {
            printf("Erro na alocação de memória!\n");
            exit(1);
        }
        novo->dado = v[i];
        novo->prox = NULL;
        novo->ant = ultimo;

        if (ultimo == NULL) {
            *lista = novo;  // Primeiro nó da lista
        } else {
            ultimo->prox = novo;  // Liga ao último nó
        }
        ultimo = novo;
    }
}

// Função para imprimir a lista duplamente encadeada
void ImprimirDupla(celulaD *lista) {
    while (lista != NULL) {
        printf("%d <-> ", lista->dado);
        lista = lista->prox;
    }
    printf("NULL\n");
}

// Função para liberar a memória alocada
void LiberarListaDupla(celulaD *lista) {
    celulaD *atual = lista;
    while (atual != NULL) {
        celulaD *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

int main() {
    int vetor[] = {5, 15, 25, 35};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    celulaD *listaDupla = NULL;

    printf("Copiando vetor para lista duplamente encadeada...\n");
    CopiarDupla(&listaDupla, vetor, tamanho);

    printf("\nLista duplamente encadeada criada:\n");
    ImprimirDupla(listaDupla);

    LiberarListaDupla(listaDupla);
    return 0;
}