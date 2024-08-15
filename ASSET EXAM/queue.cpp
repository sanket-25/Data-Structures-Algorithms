#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Function to add an element to the queue
    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to remove an element from the queue
    void dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue underflow! Cannot dequeue from an empty queue.\n";
            return;
        }

        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr; // If the queue becomes empty
        }
        delete temp;
    }

    // Function to peek at the front element of the queue
    int peek() {
        if (isEmpty()) {
            std::cerr << "Queue is empty!\n";
            return -1; // Returning -1 to indicate an error
        }
        return front->data;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to display the queue
    void display() {
        Node* current = front;
        std::cout << "Queue: ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    // Destructor to free up memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.display(); // Queue: 10 20 30

    std::cout << "Front element is: " << queue.peek() << "\n"; // Front element is: 10

    queue.dequeue();
    std::cout << "After dequeuing, front element is: " << queue.peek() << "\n"; // Front element is: 20

    queue.display(); // Queue: 20 30

    queue.dequeue();
    queue.dequeue();
    queue.dequeue(); // Attempting to dequeue from an empty queue

    return 0;
}
