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

int MaxElement(struct Node *first){
    struct Node *p=first;
    int max=first->data;
    while(p){
        if(p->data>max){
            max = p->data;
        }
        p=p->next;
    }
    return max;
}

struct Node* Insert(struct Node **first,int item,int index){
    struct Node *p=*first;
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->next = NULL;
    if(index==0){
        temp->next=*first;
        *first = temp;
        p=temp;
    }
    else{
        for(int i=0;i<index-1;i++){
        p=p->next;
    }
    temp->next=p->next;
    p->next = temp;
    }
    return p;
}

int Search(struct Node *first,int key){
    struct Node*p = first;
    int index=0;
    while(p){
        if(p->data == key){
            return index;
        }
        p=p->next;
        index++;
    }
    return -1;
}

struct Node* RemoveDuplicatesInSorted(struct Node** first){
    struct Node *p,*q;
    q=*first;
    p=q->next;
    while(p){
        if(p->data==q->data){
            p=p->next;
        }
        else{
            q->next=p;
            p=p->next;
            q=q->next;
        }
    }
    q->next=NULL;
    return *first;
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
    // printf("Recursive Reverse Display:\n ");
    // Recursive_Reverse(first);
    
    // To find the largest element
    // printf("The largest element in the list is %d ",MaxElement(first));

    // To insert a node at any given index
    // int item,index;
    // printf("Enter the data and the index to be inserted: ");
    // scanf("%d %d",&item,&index);
    // Insert(&first,item,index);
    // Display(first);

    //To search a given element
    // int key;
    // printf("Enter the element to search: ");
    // scanf("%d", &key);
    // printf("Element found at index: %d",Search(first, key));

    //To remove Duplicates in a Sorted Linked list
    RemoveDuplicatesInSorted(&first);
    Display(first);


    return 0;
}