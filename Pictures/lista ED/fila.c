#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no * prox;
}NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;


void add(int valor){
    NO * novo = malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;

    if(inicio == NULL){ // fila está vazia
        inicio = novo;
        fim = novo;
    } else {  // fim
        fim->prox = novo;
        fim = novo;
    }
    tam++;
}

int remover(){
    if(tam > 0){ // inicio
        NO *lixo = inicio;
        int valor = inicio->valor;
        inicio = inicio->prox;
        free(lixo);
        tam--;
        return valor;
    } else {
        printf("Fila vazia!\n");
        return -1;
    }
}

void imprimir(){
    NO * aux = inicio;
    printf("Fila:\n");
    for(int i = 0; i < tam; i++){
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
}

int tamanho(){
    return tam;
}

int main(){
    add(18);
    add(19);
    add(17);
    add(28);
    add(39);
    add(45);

    imprimir();
    printf("Tamanho da fila: %d\n", tamanho());
    remover();
    imprimir();
    printf("Tamanho da fila: %d\n", tamanho());
    printf("Remover: %d\n", remover());
    remover();
    imprimir();
    printf("Tamanho da fila: %d\n", tamanho());
    printf("Remover: %d\n", remover());
    add(15);
    imprimir();
    printf("Tamanho da fila: %d\n", tamanho());
    return 0;
}



