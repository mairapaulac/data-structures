/*operations: 
    push()
    pop()
    peek()
    display()
    isEmpty()
    */

#include <stdio.h>
#include <stdlib.h>

//Represents each node in the stack
typedef struct node {
    int data;
    struct node *below;
} node;

//Represents the stack itself

typedef struct stack {
    node* head;
} stack;




node* createNode(int data) {
    node* new_node = (node*)malloc(sizeof(node));

    new_node->data = data;
    new_node->below = NULL;

    return new_node;
}



//Initializing the stack

void initializeStack(stack *stack) {
    stack->head = NULL;
}

int isEmpty(stack *stack) {
   return stack->head == NULL;
}

//Push data at the top
void push(stack *stack, int data) {

    node* new_node = createNode(data);

    //Verify the memory status
    if(!new_node) {
        printf("Stack Overflow!\n");
        return;
    }

    new_node->below = stack->head;

    stack->head = new_node;

}


void pop(stack *stack) {

    //Checks if the stack is empty
    if(isEmpty(stack)) {
        printf("Stack Underflow\n");
        return;
    } else {
        node *temp = stack->head;
        stack->head = temp->below;

        free(temp);
    }   

}

//Returns the top element of the stack
int peek(stack *stack) {
    return stack->head->data;
}

void displayStack(stack *stack) {

    node *temp = stack->head;

    for(int i = 1; temp != NULL; i++) {

        printf("%d\n", temp->data);
        temp = temp->below;
    }
}



int main() {
     
    stack myStack;
    initializeStack(&myStack);

    printf("Empilhando os valores 10, 20 e 30...\n");
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    displayStack(&myStack);

    printf("\nTopo da pilha: %d\n", peek(&myStack));

    printf("\nDesempilhando...\n");
    pop(&myStack);

    displayStack(&myStack);

    printf("\nTopo da pilha: %d\n", peek(&myStack));

    return 0;
}
