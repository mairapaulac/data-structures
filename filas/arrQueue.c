/*Queue implementation using arrays*/
/*First in, First Out (FIFO)*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct queue {
    int items[MAX];
    int front;
    int rear;
}queue;


void createQueue(queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(queue* queue) {
    return queue->rear == MAX - 1;
}

int isEmpty(queue* queue) {
    return queue->front == -1;
}

void enqueue(queue* queue, int val) {
    if(isFull(queue)) {
        printf("Stack Overflow!");
        return;
    }
    
    if(queue->front == -1)
        queue->front = 0;

    queue->rear++;
    queue->items[queue->rear] = val;
    printf("Enqueued: %d\n", val);
}

int dequeue(queue* queue) {
    if(isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }

    int dequeuedItem = queue->items[queue->front];
    if(queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }

    return dequeuedItem;
}

int main() {
    queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
enqueue(&q, 30);
    printf("Dequeued: %d\n", dequeue(&q));
    return 0;
}
