#include <stdio.h>

#define STACK_SIZE 100

// Definição da estrutura de dados da pilha
typedef struct
{
    int stack[STACK_SIZE];
    int top; // Índice do topo da pilha
} Stack;

// Função para inicializar a pilha
void initStack(Stack *s)
{
    s->top = -1; // Inicializa o topo da pilha como -1 (indicando pilha vazia)
}

// Função para empilhar um valor na pilha
void push(Stack *s, int value)
{
    if (s->top < STACK_SIZE - 1)
    {
        s->top++;
        s->stack[s->top] = value;
    }
    else
    {
        printf("Stack overflow\n");
    }
}

// Função para desempilhar um valor da pilha
int pop(Stack *s)
{
    if (s->top >= 0)
    {
        int value = s->stack[s->top];
        s->top--;
        return value;
    }
    else
    {
        printf("Stack underflow\n");
        return -1; // Valor arbitrário para indicar erro
    }
}

int main()
{
    Stack s;
    initStack(&s);

    // Exemplo de utilização
    push(&s, 5);
    push(&s, 10);
    push(&s, 7);

    printf("Desempilhando valores:\n");
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));

    return 0;
}