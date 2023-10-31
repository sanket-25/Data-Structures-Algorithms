#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * start = NULL;

struct node * createLinkedList(struct node * start) {
    struct node * newNode;
    struct node * ptr;

    int value;
    printf("Enter -1 to end\n");
    printf("Enter the data : ");
    scanf("%d", &value);

    while (value != -1) {

        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = value;

        if (start == NULL) {
            start = newNode;
            newNode->next = NULL;
        }
        else {
            ptr = start;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->next = NULL;
        }

        printf("Enter the data : ");
        scanf("%d", &value);
    }
    
    return start;
}

struct node * traverseLinkedList(struct node * start){
    struct node * ptr;
    ptr=start;
    while(ptr!=NULL){
        printf("Elements are : %d\n", ptr->data);
        ptr=ptr->next;
    }
    return start;
}

struct node * insertBeginning(struct node * start){
    printf("Insert Node at beginning\n");
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    
    int value;
    printf("Enter the data : ");
    scanf("%d", &value);
    
    newNode->data=value;
    newNode->next=start;
    start=newNode;
    return start;
}

struct node * insertEnding(struct node * start){
    printf("Insert Node at ending\n");
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    struct node * ptr;
    
    int value;
    printf("Enter the data : ");
    scanf("%d", &value);
    
    newNode->data=value;
    
    ptr=start;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    
    ptr->next=newNode;
    newNode->next=NULL;
    
    return start;
    
}



int main() {
    start = createLinkedList(start);
    start = traverseLinkedList(start);
    start = insertBeginning(start);
    start = insertEnding(start);
    start = traverseLinkedList(start);
    return 0;
}
