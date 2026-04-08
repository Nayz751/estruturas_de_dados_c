#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char operador;
    int numero;
    struct no *prox;
} No;

No *novoNo(char operador, int numero) {
    No *novo = (No*) malloc(sizeof(No));
    novo->operador = operador;
    novo->numero = numero;
    novo->prox = NULL;
    return novo;
}

int operacao(int num1, int num2, char op) {
    if (op == '+')
        return num1 + num2;
    if (op == '-')
        return num1 - num2;
    if (op == '*')
        return num1 * num2;
    if (op == '/')
        return num1 / num2;
}

int calcular(No **expressao) {
    if ((*expressao)->prox == NULL)
        return (*expressao)->numero;
    
    int num1 = (*expressao)->numero;
    int num2 = (*expressao)->prox->numero;
    char op = (*expressao)->prox->operador;
    
    (*expressao)->prox = (*expressao)->prox->prox;
    (*expressao)->numero = operacao(num1, num2, op);
    
    return calcular(expressao);
}

int main() {
    No *n5 = novoNo('n', 5);
    No *n4 = novoNo('n', 4);
    No *n3 = novoNo('n', 3);
    No *n2 = novoNo('n', 2);
    No *n1 = novoNo('n', 1);
    No *op1 = novoNo('+', 0);
    No *op2 = novoNo('*', 0);
    No *op3 = novoNo('-', 0);
    No *op4 = novoNo('/', 0);
    
    op1->prox = n4;
    n4->prox = n5;
    
    op2->prox = n3;
    n3->prox = n2;
    
    op3->prox = op2;
    op2->prox = op1;
    
    op4->prox = n1;
    n1->prox = op3;
    
    int resultado = calcular(&op4);
    printf("Resultado: %d\n", resultado);
    
    return 0;
}
