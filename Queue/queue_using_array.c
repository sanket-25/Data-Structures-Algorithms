#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a structure for the queue
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function to initialize the queue
void initialize(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q) {
    return q->front == -1;
}

// Function to check if the queue is full
int isFull(struct Queue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

// Function to enqueue (insert) an element into the queue
void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->items[q->rear] = value;
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int dequeuedItem = q->items[q->front];
    if (q->front == q->rear) {
        // If there was only one element in the queue
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return dequeuedItem;
}

int main() {
    struct Queue q;
    initialize(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printf("Dequeued item: %d\n", dequeue(&q));
    printf("Dequeued item: %d\n", dequeue(&q));

    enqueue(&q, 50);
    enqueue(&q, 60);

    printf("Dequeued item: %d\n", dequeue(&q));
    printf("Dequeued item: %d\n", dequeue(&q));

    return 0;
}
