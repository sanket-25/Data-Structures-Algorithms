#include <stdio.h>

struct node{
    int data;
    struct node * next;
};

void traverse(struct node * head){
    struct node * ptr = head;
    do{
        printf("Element: %d\n", ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}

int main(){
    struct node * first = (struct node *)malloc(sizeof(struct node));
    struct node * second = (struct node *)malloc(sizeof(struct node));
    struct node * third = (struct node *)malloc(sizeof(struct node));
    struct node * fourth = (struct node *)malloc(sizeof(struct node));
    struct node * fifth = (struct node *)malloc(sizeof(struct node));
    
    first->data=1;
    first->next=second;
    
    second->data=3;
    second->next=third;
    
    third->data=5;
    third->next=fourth;
    
    fourth->data=7;
    fourth->next=fifth;
    
    fifth->data=9;
    fifth->next=first;
    
    struct node * head;
    head=first;
    
    traverse(head);
    
    
}