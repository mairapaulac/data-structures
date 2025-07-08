#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Converting an infix expression into a postfix expression using stacks */
/* Algoritmo Shunting Yard */

typedef struct node {
    char data;
    struct node *next;
}node;


node* createNode(char data) {
    node* newNode = (node*)malloc(sizeof(node));

    if(!newNode) {
        printf("Nao foi possivel alocar memoria\n");
        return 0;
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void pushItem(node** stackTop, char data) {
    node* newNode = createNode(data);
    newNode->next = *stackTop;
    *stackTop = newNode;
}

int isEmpty(node* stackTop) {
    return (stackTop == NULL);
}

char popItem(node** stackTop) {
    node* temp = *stackTop;

     if(isEmpty(*stackTop)) {
        printf("Stack overflow");
        exit(1);
    }

    char poppedItem = temp->data;
    *stackTop = temp->next; 
    free(temp);

    return poppedItem;
}

int precedenceOfOperator(char op) {
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int peek(node* stackTop) {
    return stackTop->data;
}

char* postfixExpression(char* expression) {
    char* postExp = (char*)malloc(200 * sizeof(char)); 
    node* stack = NULL;
    int j = 0;

    for(int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            postExp[j++] = c;
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            while(stack != NULL && precedenceOfOperator(peek(stack) >= precedenceOfOperator(c))) {
                postExp[j++] = popItem(&stack);
            }
            pushItem(&stack, c);
        } else if (c == '(') {
            pushItem(&stack, c);
        } else if (c == ')') {
            while (stack != NULL && peek(stack) != '(') {
                postExp[j++] = popItem(&stack);
            }
            if(stack != NULL && peek(stack) == '(') {
                popItem(&stack);
            }
        }
    }

    while (stack != NULL) {
        postExp[j++] = popItem(&stack);
    }

    postExp[j] = '\0';

    return postExp;
}


int main() {
    char expression[200];

    printf("Digite uma expressao infixa: ");
    fgets(expression, sizeof(expression), stdin);

    size_t len = strlen(expression);
    if (len > 0 && expression[len - 1] == '\n') {
        expression[len - 1] = '\0';
    }

    char* result = postfixExpression(expression);
    printf("Expressao pos-fixa: %s\n", result);

    free(result); 

    return 0;
}
