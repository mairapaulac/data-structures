/* Write a program to check the validity of the expression containing nested brackets */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The total number of left brackets has to be equal to the number of the right brackets*/

typedef struct node {
    char data;
    struct node* next;
} node;

node* createNode(char data) {
    node* newNode = (node*)malloc(sizeof(node));

    if(!newNode) {
        printf("Nao foi possivel alocar memoria");
        exit(1);
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

char popItem(node** stackTop) {

    if(*stackTop == NULL) {
        printf("Stack overflow");
        exit(1);
    }

    node* temp = *stackTop;
    char poppedItem = temp->data;
    *stackTop = temp->next;
    free(temp);

    return poppedItem;
}


int isEmpty (node* top) {
    return (top == NULL);
}

//checking pairs

int isMatchingPair(char left, char right) {
    return (left == '(' && right == ')') ||
           (left == '[' && right == ']') ||
           (left == '{' && right == '}');
}

int checkValidity(const char* expression) {
    node* stack = NULL;

    for(int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];
        if (c == '(' || c == '{' || c == '[') {
            pushItem((&stack), expression[i]);
        } else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty(stack)) 
                return 0;

            char top = popItem(&stack);
            if(!isMatchingPair(top, c)) {
                printf("Invalid Expression\n");
                return 0;
            }
        }
    }

    int valid = isEmpty(stack);

    while (!isEmpty(stack)) {
        popItem(&stack);
    }

    return valid;
}


int main() {
    char exp[100];
    printf("Digite a expressao: ");
    fgets(exp, sizeof(exp), stdin);

    if(checkValidity(exp)) {
        printf("Expressao valida!\n");
    } else {
        printf("Expressao invalida!\n");
    }

    return 0;
}