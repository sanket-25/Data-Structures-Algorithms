#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a structure for the stack
struct stack {
    int items[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct stack *s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(struct stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct stack *s, int value) {
    if (isFull(s)) {
        printf("stack overflow\n");
        return;
    }
    s->items[++s->top] = value;
}

// Function to pop an element from the stack
int pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("stack underflow\n");
        return -1;
    }
    return s->items[s->top--];
}

// Function to peek at the top element of the stack
int peek(struct stack *s) {
    if (isEmpty(s)) {
        printf("stack is empty\n");
        return -1;
    }
    return s->items[s->top];
}

int main() {
    struct stack s;
    initialize(&s);

    // Push 10 elements onto the stack
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);
    push(&s, 60);
    push(&s, 70);
    push(&s, 80);
    push(&s, 90);
    push(&s, 100);

    // Create an array to store the popped elements
    int poppedArray[MAX_SIZE];
    int poppedIndex = 0;

    // Pop elements from the stack and store them in the array
    while (!isEmpty(&s)) {
        int poppedElement = pop(&s);
        poppedArray[poppedIndex++] = poppedElement;
    }

    // Print the popped elements stored in the array
    printf("Popped elements: ");
    for (int i = poppedIndex - 1; i >= 0; i--) {
        printf("%d ", poppedArray[i]);
    }
    printf("\n");

    return 0;
}
