// linkedlist.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    int data;
    struct Node *next;
};

void createNode(int A[], int n, struct Node **first);
void Display(struct Node *p);

#endif
