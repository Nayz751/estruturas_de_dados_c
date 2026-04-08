#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int peso;
    struct no* prox;
} NO;

typedef struct pilha {
    NO* inicio;
    int tam;
} PILHA;

void add(int peso, PILHA* p) {
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->peso = peso;
    novo->prox = p->inicio;
    p->inicio = novo;
    p->tam++;
}

int remover(PILHA* p) {
    int peso_retornado = -1;
    if (p->inicio != NULL) {
        NO* lixo = p->inicio;
        peso_retornado = p->inicio->peso;
        p->inicio = p->inicio->prox;
        free(lixo);
        p->tam--;
    }
    return peso_retornado;
}

void inicia(PILHA* p) {
    p->inicio = NULL;
    p->tam = 0;
}

void imprimir(PILHA* p) {
    NO* atual = p->inicio;
    printf("[ ");
    while (atual != NULL) {
        printf("%d ", atual->peso);
        atual = atual->prox;
    }
    printf("]\n");
}

int main() {
    PILHA* a = (PILHA*) malloc(sizeof(PILHA));
    PILHA* b = (PILHA*) malloc(sizeof(PILHA));
    PILHA* c = (PILHA*) malloc(sizeof(PILHA));

    inicia(a);
    inicia(b);
    inicia(c);

    add(7, a);
    add(3, b);
    add(5, c);

    imprimir(a);
    imprimir(b);
    imprimir(c);

    printf("Removendo %d\n", remover(add));

    return 0;
}