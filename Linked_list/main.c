#include "linkedlist.h"
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, element;
    int A[100];
    struct Node *first = NULL;

    printf("Initial Linked List creation: \n");
    printf("Enter the number of elements to be added initially: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &element);
        A[i] = element;
    }
    createNode(A, n, &first);
    Display(first);
    return 0;
}