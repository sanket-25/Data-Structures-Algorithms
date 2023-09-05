#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
};

struct node * insertionBetween(struct node * head, int index, int value){
    struct node * new = (struct node *)malloc(sizeof(struct node));
    struct node * ptr = head;
    
    int i=1;
    while(i!=index){
        ptr = ptr->next;
        i++;
    }
    new->next=ptr->next;
    new->data=value;
    ptr->next=new;
    return head;
}

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
    
    //struct node head, index, data
    head=insertionBetween(head, 2, 25);
    transverse(head);
    
    return 0;
    
}