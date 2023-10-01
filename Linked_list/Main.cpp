#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

void createNode(int A[], int n, struct Node **first) {
    struct Node *p, *last;
    p = new Node;
    p->data = A[0];
    p->next = NULL;
    last = p;
    *first = p;

    for (int i = 1; i < n; i++) {
        struct Node *t = new Node;
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
            cout<<"-> ";
        }
        p = p->next;
    }
    cout<<"\n";
}

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
        cout<<p->data+" -> ";
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
    struct Node *temp = new Node;
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


int main(){
    int n, element,index;
    int A[100];
    struct Node *first = NULL;

    cout<<"Initial Linked List creation: ";
    cout<<"Enter the number of elements to be added initially: ";
    cin>>n;
    for (int i = 0; i < n; i++) {
        cout<<"Element "<< (i + 1)<<": ";
        cin>>element;
        A[i] = element;
    }
    createNode(A, n, &first);
    Display(first);

    // For Kth element from the end 
    cout<<"Enter the place of the element to be obtained from the end  ";
    cin>>index;
    cout<<"The " << index << " element from the end is "<< FromEnd(first,index);

    
    return 0;
}