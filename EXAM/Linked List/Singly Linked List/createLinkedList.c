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

int main() {
    createLinkedList(start);
    return 0;
}
