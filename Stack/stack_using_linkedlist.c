#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for the stack
struct Stack {
    struct Node* top;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the stack
void initialize(struct Stack* s) {
    s->top = NULL;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == NULL;
}

// Function to push an element onto the stack
void push(struct Stack* s, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = s->top;
    s->top = newNode;
}

// Function to pop an element from the stack
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    struct Node* temp = s->top;
    int poppedValue = temp->data;
    s->top = temp->next;
    free(temp);
    return poppedValue;
}

// Function to peek at the top element of the stack
int peek(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->top->data;
}

int main() {
    struct Stack s;
    initialize(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", peek(&s));

    printf("Popped element: %d\n", pop(&s));
    printf("Popped element: %d\n", pop(&s));

    printf("Is the stack empty? %s\n", isEmpty(&s) ? "Yes" : "No");

    return 0;
}
