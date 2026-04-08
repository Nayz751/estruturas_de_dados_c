#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    int prioridade;
    struct no *prox;
} NO;

NO *inicio = NULL;
int tam = 0;

void add(int valor, int prioridade) {
    NO *novo = (NO*) malloc(sizeof(NO));
    novo->valor = valor;
    novo->prioridade = prioridade;
    novo->prox = NULL;
    
    if (inicio == NULL) { 
        inicio = novo;
    } else { 
        NO *aux = inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    tam++;
}

int remover() {
    if (inicio == NULL) { 
        printf("Fila vazia!\n");
        return -1;
    }
    NO *aux = inicio;
    NO *ant = NULL;
    NO *maior_prioridade = inicio;
    while (aux != NULL) { 
        if (aux->prioridade > maior_prioridade->prioridade) {
            ant = maior_prioridade;
            maior_prioridade = aux;
        }
        aux = aux->prox;
    }
    int valor = maior_prioridade->valor;
    if (maior_prioridade == inicio) { 
        inicio = maior_prioridade->prox;
    } else { 
        ant->prox = maior_prioridade->prox;
    }
    free(maior_prioridade);
    tam--;
    return valor;
}

void imprimir() {
    NO *aux = inicio;
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

int main() {
    add(1, 4);
    add(50, 5);
    add(22, 6);
    imprimir(); 
    
    remover();
    imprimir(); 
    
    add(15, 5);
    imprimir(); 
    
    
    return 0;
}
