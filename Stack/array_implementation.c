#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int * arr;
};

int isFull(struct stack * ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct stack * ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int push(struct stack * ptr, int data){
    if(!isFull){
        ptr->top++;
        ptr->arr[ptr->top]=data;
    }
    else{
        printf("Stack Overflow\n");
    }
}

int pop(struct stack * ptr){
    if(!isEmpty){
        ptr->top--;
    }
    else{
        printf("Stack Underflow\n");
    }
}

int main(){
    struct stack * s=(struct stack *)malloc(sizeof(struct stack));
    s->size=10;
    s->top=-1;
    s->arr=(int *)malloc(s->size*sizeof(int));
    
    push(s, 1);
    push(s, 3);
    push(s, 5);
    push(s, 7);
    pop(s);
    
    for(int i=0; i<s->size; i++){
        printf("%d\n", s->arr[i]);
    }
    
    return 0;
}