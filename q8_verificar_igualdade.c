#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Estrutura de uma célula de uma lista simplesmente encadeada
typedef struct Celula {
    int dado;
    struct Celula* prox;
} Celula;

// Função para verificar se duas listas são iguais
bool saoIguais(Celula* lista1, Celula* lista2) {
    // Percorre as duas listas
    while (lista1 != NULL && lista2 != NULL) {
        // Se os dados não são iguais, retorna false
        if (lista1->dado != lista2->dado) {
            return false;
        }
        lista1 = lista1->prox;
        lista2 = lista2->prox;
    }

    // Se uma lista acabou e a outra não, retorna false
    return lista1 == NULL && lista2 == NULL;
}

// Função para criar uma nova célula
Celula* novaCelula(int valor) {
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->dado = valor;
    nova->prox = NULL;
    return nova;
}

int main() {
    // Criando duas listas para teste
    Celula* lista1 = novaCelula(1);
    lista1->prox = novaCelula(2);
    lista1->prox->prox = novaCelula(3);

    Celula* lista2 = novaCelula(1);
    lista2->prox = novaCelula(2);
    lista2->prox->prox = novaCelula(3);

    // Verificando se as listas são iguais
    if (saoIguais(lista1, lista2)) {
        printf("As listas são iguais.\n");
    } else {
        printf("As listas são diferentes.\n");
    }

    return 0;
}
