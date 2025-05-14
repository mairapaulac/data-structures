#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} node;

//criando a cabeça da lista
void cria_cabeca(node **head) {
    *head = NULL;
};

//mostrar os elementos da lista
void printa_lista(node *head) {
    node *temp = head;

    while (temp != NULL) {
        printf("%d ", (temp)->data);
        temp = temp->next;
    }
}

//retorna o tamanho da lista
int tamanho_lista(node **head) {
    int cont = 0;
    node *temp = *head;

    while (temp != NULL){
        temp = temp->next;
        cont++;
    }

    return cont;            
}

//inserindo ao final
void insere_final(node **head, int value) {
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

//inserir em uma dada posição
void insere_em_k_pos(node **head, int value, int pos) { 
    node *new_node = (node*)malloc(sizeof(node));

    if(new_node == NULL)
        printf("Erro ao alocar memoria\n");

    if(pos == 0 || pos > tamanho_lista(head))
        printf("Erro, posicao invalida");

   new_node->data = value;
   new_node->next = NULL;

   if(*head == NULL) {
        *head = new_node;
   
   }

    if(pos == 1) {
        new_node->next = *head;
        *head = new_node;
    } else {
        node *temp = *head;
            for (int i = 0; i < pos - 1 && temp != NULL; i++) {
                    temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }      


bool procura_elemento(node **head, int key) {
    node *temp = *head;

    while(temp != NULL) {
        if (temp->data)
            return true;
            
            
        temp = temp->next;
    }
    return false;
}






int main (void) {

    node *list;

    create_head(&list);
    insert_end(&list, 1);
    insert_end(&list, 2);
    insert_end(&list, 3);
    insert_end(&list, 4);
    insert_end(&list, 5);
    insert_end(&list, 10);
    insert_end(&list, 9);
    insert_end(&list, 8);
    insert_end(&list, 7);

    printf("Tamanho: %d\n", tamanho_lista(&list));

    print_list(list);
}