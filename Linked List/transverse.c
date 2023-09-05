#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
};

void transverse(struct node * ptr){
    while(ptr!=NULL){
        printf("Element: %d\n", ptr->data);
        ptr=ptr->next;
    }
}

int main(){
    struct node * first = (struct node *)malloc(sizeof(struct node));
    struct node * second = (struct node *)malloc(sizeof(struct node));
    struct node * third = (struct node *)malloc(sizeof(struct node));
    struct node * fourth = (struct node *)malloc(sizeof(struct node));
    struct node * fifth = (struct node *)malloc(sizeof(struct node));
    
    struct node * head;
    head = first;
    
    first->data=1;
    first->next=second;
    
    second->data=3;
    second->next=third;
    
    third->data=5;
    third->next=fourth;
    
    fourth->data=7;
    fourth->next=fifth;
    
    fifth->data=9;
    fifth->next=NULL;
    
    transverse(head);
    
    return 0;
    
}