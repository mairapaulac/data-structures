#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

//criando a cabeça da lista
void create_head(node **head) {
    *head = (node*)malloc(sizeof(node));
    if (*head != NULL) {
        (*head)->next = NULL;
    } else {
        printf("Erro ao alocar memoria\n");
    }
};

void print_list(node *head) {
    node *temp = head;

    while (temp != NULL) {
        printf("%d ", (temp)->data);
        temp = temp->next;
    }
}

//inserindo ao final
void insert_end(node **head, int value) {
    node *new_node = (node*)malloc(sizeof(node)); 
    

    // verificando se conseguimos alocar
    if(new_node == NULL)
        printf("Erro ao alocar memoria\n");
   
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        node *temp = *head;
        //percorremos a lista se ela nao tiver vazia
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

//inserir no começo da lista
void insert(node **head, int value) { 
    node *new_node = (node*)malloc(sizeof(node));

    if(new_node == NULL)
        printf("Erro ao alocar memoria\n");

   new_node->data = value;
   new_node->next = NULL;

   if(*head == NULL) {
        *head = new_node;
   } else {
       
        new_node->next = *head;
        *head = new_node;
   }

}



int main (void) {

    node *list;

    create_head(&list);
    insert_end(&list, 1);
    insert_end(&list, 2);
    insert_end(&list, 3);
    insert_end(&list, 4);
    insert_end(&list, 5);
    insert(&list, 10);
    insert(&list, 9);
    insert(&list, 8);
    insert(&list, 7);

    print_list(list);
}