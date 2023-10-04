#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st){
    printf("Enter the size of the stack: ");
    scanf("%d",&st->size);
    st->top=-1;
    st->S=(int*)malloc(st->size*sizeof(int));
}

int isEmpty(struct Stack st){
    if(st.top==-1)
        return 1;
    return 0;
}

int isFull(struct Stack st){
    if(st.top==st.size-1)
        return 1;
    return 0;
}

void push(struct Stack *st,int x){
    if(isFull(*st))
        printf("Stack Overflow\n");
    else{
        st->top++;
        st->S[st->top]=x;
    }
}

int pop(struct Stack *st){
    int x=-1;
    if(isEmpty(*st))
        printf("Stack Underflow\n");
    else{
        x=st->S[st->top];
        st->top--;
    }
    return x;
}

void Display(struct Stack st){
    for(int i=st.top;i>=0;i--){
        printf("%d ",st.S[i]);
    }
    printf("\n");
}

int peekFromTop(struct Stack st,int index){
    int x=-1;
    if(st.top-index<0){
        printf("Invalid position");
    }
    x=st.S[st.top-index];
    return x;
}

int main(){
    struct Stack st;
    create(&st);
    int choice,index,number;
    while(1){
        printf("Enter your choice:\n");
    printf("1.push");
    printf("2.pop");
    printf("3.peek");
    printf("4.display");
    printf("5.exit");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter the number to be pushed: ");
            scanf("%d",&number);
            push(&st,number);
            break;
        case 2:
            printf("%d",pop(&st));
            break;
        case 3:
            printf("Enter the position: ");
            scanf("%d",&index);
            printf("%d",peekFromTop(st,index));
            break;
        case 4:
            Display(st);
            break;
        case 5:
            return 0;
            break;
    }
    }
    return 0;
}