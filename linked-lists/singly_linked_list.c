#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} node;

// cria cabeça
void cria_cabeca(node **head) {
    *head = NULL;
}

// imprime lista
void printa_lista(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// tamanho da lista
int tamanho_lista(node **head) {
    int cont = 0;
    node *temp = *head;
    while (temp != NULL) {
        cont++;
        temp = temp->next;
    }
    return cont;
}

// insere no final
void insere_final(node **head, int value) {
    node *new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Erro ao alocar memoria\n");
        return;
    }
    new_node->data = value;
    new_node->next = NULL;

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

// insere em uma posição k (1-indexado)
void insere_em_k_pos(node **head, int value, int pos) {
    node *new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Erro ao alocar memoria\n");
        return;
    }
    new_node->data = value;
    new_node->next = NULL;

    int tamanho = tamanho_lista(head);
    if (pos < 1 || pos > tamanho + 1) {
        printf("Erro, posicao invalida\n");
        free(new_node);
        return;
    }

    if (pos == 1) {
        new_node->next = *head;
        *head = new_node;
    } else {
        node *temp = *head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

// procura elemento
bool procura_elemento(node **head, int key) {
    node *temp = *head;
    while (temp != NULL) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}


void deletar_uma_pos(node **head, int pos) {
    int tamanho = tamanho_lista(head);
    if (pos < 1 || pos > tamanho) {
        printf("Posicao invalida!\n");
        return;
    }

    node *temp = *head;
    if (pos == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    node *prev = NULL;
    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (prev != NULL && temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }
}

int main(void) {
    node *list;
    cria_cabeca(&list);

    // inserir elementos no final
    insere_final(&list, 1);
    insere_final(&list, 2);
    insere_final(&list, 3);
    insere_final(&list, 4);
    insere_final(&list, 5);
    insere_final(&list, 10);
    insere_final(&list, 9);
    insere_final(&list, 8);
    insere_final(&list, 7);

    printf("Lista inicial: ");
    printa_lista(list);
    printf("Tamanho: %d\n", tamanho_lista(&list));

    // deletar posição 1
    printf("Deletando posicao 1...\n");
    deletar_uma_pos(&list, 1);
    printa_lista(list);
    printf("Tamanho: %d\n", tamanho_lista(&list));

    // inserir na posição 3
    printf("Inserindo 99 na posicao 3...\n");
    insere_em_k_pos(&list, 99, 3);
    printa_lista(list);
    printf("Tamanho: %d\n", tamanho_lista(&list));

    // procurar elemento 5
    printf("Procurando elemento 5: %s\n", procura_elemento(&list, 5) ? "Encontrado" : "Nao encontrado");

    // deletar posição inválida
    printf("Tentando deletar posicao 20...\n");
    deletar_uma_pos(&list, 20);

    // mostrar lista final
    printf("Lista final: ");
    printa_lista(list);

    return 0;
}
