#include<stdio.h>
#include<stdlib.h>


typedef struct no{
    int valor;
    struct no * prox;
}NO;

NO * inicio = NULL; //topo
int tam = 0;

void add(int valor) {
    NO *novo = (NO*) malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;
    
    if (inicio == NULL) { // fila vazia
        inicio = novo;
    } else if (valor <= inicio->valor) { // nova prioridade é menor ou igual à primeira
        novo->prox = inicio;
        inicio = novo;
    } else { // nova prioridade é maior que a primeira
        NO *aux = inicio;
        while (aux->prox != NULL && valor > aux->prox->valor) {
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
    }
    tam++;
}

int remover() {
    if (inicio == NULL) { // fila vazia
        printf("Fila vazia!\n");
        return -1;
    }
    NO *aux = inicio;
    int valor = aux->valor;
    inicio = inicio->prox;
    free(aux);
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
    add(10);
    add(5);
    add(20);
    imprimir(); 
    
    remover();
    imprimir(); 
    
    add(15);
    imprimir(); 
    
    return 0;
}
