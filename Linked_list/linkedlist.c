// linkedlist.c

#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

void createNode(int A[], int n, struct Node **first) {
    struct Node *p, *last;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = A[0];
    p->next = NULL;
    last = p;
    *first = p;

    for (int i = 1; i < n; i++) {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        last->next = t;
        t->next = NULL;
        last = t;
    }
}

void Display(struct Node *p) {
    while (p) {
        printf("%d ", p->data);
        if (p->next != NULL) {
            printf("-> ");
        }
        p = p->next;
    }
    printf("\n");
}
