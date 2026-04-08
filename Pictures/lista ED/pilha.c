#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no * prox;
}NO;

NO * inicio = NULL; 
int tam = 0;

void add(int valor){
    NO * novo = malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;

    if(inicio == NULL){ 
        inicio = novo;
    } else {
        novo->prox = inicio;
        inicio = novo;
    }
    tam++;
}

int remover(){
    if(tam > 0){
        NO *lixo = inicio;
        int valor = inicio->valor;
        inicio = inicio->prox;
        free(lixo);
        tam--;
        return valor;
    } else {
        printf("Pilha vazia!\n");
        return -1;
    }
}

void imprimir(){
    NO * aux = inicio;
    printf("Pilha atual:\n");
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
    
    remover();
    
    imprimir();
    
    printf("remover: %d\n", remover());
    printf("Tamanho da pilha: %d\n", tamanho());

    imprimir();
    printf("remover: %d\n", remover());
    printf("Tamanho da pilha: %d\n", tamanho());
    
    return 0;
}
