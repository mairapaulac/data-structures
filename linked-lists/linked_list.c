#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void create_head(node **head) {
    *head = (node*)malloc(sizeof(node));
    if (*head != NULL) {
        (*head)->data = 0;
        (*head)->next = NULL;
    }
};

void insert_end(node **head, int value) {
    node *new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Erro ao alocar memória\n");
    }

    if (*head == NULL) {
        *head = new_node;
    } else {
        node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = new_node;
    }
}

// inserindo no começo
void insert(node **head, int value) { 
    node *new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Erro ao alocar memória\n");
    }

        new_node->data = value;
        new_node->next = *head;
        *head = new_node;
        
}

int main (void) {

}