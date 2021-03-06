#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

// implementar lista duplamente encadeada
// inserir/remover inicio
// inserir/remover meio
// inserir/remover fim

node* init() {
    return NULL;
};

int empty_queue(node *head) {
    if (head == NULL) {
        return 1;
    }
    return 0;
};

node * push(node *current, int value) {
    node *next;
    next = (node *) malloc(1*sizeof(node));
    if (next != NULL) {
        next->num = value;
        next->prox = NULL;
        if (current != NULL)
            current->prox = next;
    }
    return next;
};

node * pop(node *head) {
    node *new_head;
    new_head = head->prox;
    free(head);
    return new_head;
};

node * middlepush(node *head, int pos, int value) {
    node *new_val, *current, *last;
    current = head;
    last = head;
    new_val = (node *) malloc(1*sizeof(node));

    if (current != NULL && new_val != NULL) {
        while (current->prox != NULL && current->num != pos) {
            last = current;
            current = current->prox;
        }
        new_val->num = value;
        new_val->prox = current;
        last->prox = new_val;
    }

    return head;
};

void print_queue(node *head) {
    node *test=NULL;
    test = head;
    do {
        printf("[%x] = %d, ", test, test->num);
        test = test->prox;
    } while (test != NULL);
    printf("\n");
};
