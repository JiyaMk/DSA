#include "linkedlist.h"
#include<stdio.h>
#include<stdlib.h>

int FromEnd(struct Node *first,int k){
    struct Node *p=first;
    struct Node *q=first;
    for(int i=0;i<k;i++){
        p=p->next;
    }
    while(p!=NULL){
        p=p->next;
        q=q->next;
    }
    return q->data;
}

void Recursive_Reverse(struct Node *first){
    struct Node *p=first;
    if(p!=NULL){
        Recursive_Reverse(p->next);
        printf("%d -> ",p->data);
    }
}
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

    // For Kth element from the end 
    // printf("Enter the place of the element to be obtained from the end  ");
    // scanf("%d",&index);
    // printf("The %d element from the end is %d ",index,FromEnd(first,index));

    // For Reversing a linked list using recursion
    printf("Recursive Reverse Display:\n ");
    Recursive_Reverse(first);
    
    return 0;
}