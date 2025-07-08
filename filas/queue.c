/* Implementação de uma fila utilizando linked lists*/
/*  Operações
*   enqueue() 
*   dequeue()
*   peek()
*   isEmpty()
*/

#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó
typedef struct node{
    int data;
    struct node *next;
}node;

// Estrutura de uma fila
typedef struct queue {
    struct node *rear;
    struct node *front;
} queue;


// Criar nós
node *new_node(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

//Inicializar a fila
queue *init_queue() {
    queue* newQueue = (queue*)malloc(sizeof(queue));
    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}

//Verifica se a fila está vazia
int is_empty(queue* q) {
    return q->front == NULL;
}

void enqueue(queue* q, int data) {
    //Criamos um novo nó
    node* newNode = new_node(data);
    
    //Verificamos se está vazia, adicionando o primeiro elemento
    if(is_empty(q)) {
        q->front = q->rear = newNode;
        return;  
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

void dequeue(queue* q) {
    //Verificamos se a lista está vazia
    if(is_empty(q)) {
        return;
    }

    node* temp = q->front;
    q->front = q->front->next;
    
    if(q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
}

int peek(queue* q) {
    return q->front->data;
}

void print_queue(queue* q) {
    if(is_empty(q)) {
        printf("A fila esta vazia!\n");
        return;
    }

    node* temp = q->front;
    printf("Fila atual: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    queue* q = init_queue();

   
    enqueue(q, 10);
    enqueue(q, 20);

    dequeue(q);
    dequeue(q);

    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    
    dequeue(q);

    print_queue(q);
    
    return 0;
}
