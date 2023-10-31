#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * start = NULL;

struct node * traverseLinkedList(struct node * start){
    struct node * ptr;
    ptr=start;
    while(ptr!=NULL){
        printf("Elements are : %d\n", ptr->data);
        ptr=ptr->next;
    }
    return start;
}



struct node * insertBetween(struct node * start){
    printf("--x--x--Insert Between--x--x--\n");
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    struct node * ptr;
    struct node * pptr;
    
    int value;
    printf("Enter the data : ");
    scanf("%d", &value);
    
    newNode->data=value;
    
    int beforeValue;
    printf("Enter the data after which to be inserted : ");
    scanf("%d", &beforeValue);
    
    ptr=start;
    while(ptr->data!=beforeValue){
        pptr=ptr;
        ptr=ptr->next;
    }
    pptr=ptr->next;
    
    ptr->next=newNode;
    newNode->next=pptr;
    
    return start;
}

int main() {
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
    fifth->next=NULL;
    
    start = first;
    
    start = traverseLinkedList(start);
    start = insertBetween(start);
    start = traverseLinkedList(start);
    return 0;
}
