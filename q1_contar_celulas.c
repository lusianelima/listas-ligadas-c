#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int x;
    struct celula *prox;
} celula;

// Contagem SEM cabeça (iterativa)
int conta_sem_cabeca(celula *lista) {
    int count = 0;
    celula *atual = lista;
    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }
    return count;
}

// Contagem COM cabeça (iterativa)
int conta_com_cabeca(celula *cabeca) {
    int count = 0;
    celula *atual = cabeca->prox; // Pula a cabeça!
    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }
    return count;
}

// Função auxiliar para criar lista COM cabeça
celula *cria_lista_com_cabeca() {
    celula *cabeca = malloc(sizeof(celula));
    cabeca->prox = NULL; // Lista vazia
    return cabeca;
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
    // Lista SEM cabeça
    celula *lista_sem = cria_lista_exemplo();
    printf("Sem cabeca: %d celulas\n", conta_sem_cabeca(lista_sem));

    // Lista COM cabeça
    celula *lista_com = cria_lista_com_cabeca();
    
    celula *no1 = malloc(sizeof(celula));
    no1->x = 10; 
    
    celula *no2 = malloc(sizeof(celula));
    no2->x = 20; 
    no2->prox = NULL;  
    
    lista_com->prox = no1;
    no1->prox = no2;  
    
    printf("Com cabeca: %d celulas\n", conta_com_cabeca(lista_com));

    // Libera a memória
    free(lista_sem->prox->prox);
    free(lista_sem->prox);
    free(lista_sem);
    free(lista_com->prox->prox);  // Libera no2
    free(lista_com->prox);        // Libera no1
    free(lista_com);              // Libera cabeça

    return 0;
}