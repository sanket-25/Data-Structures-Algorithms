#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    Stack() : top(nullptr) {}

    // Function to push an element onto the stack
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    // Function to pop the top element from the stack
    void pop() {
        if (isEmpty()) {
            std::cerr << "Stack underflow! Cannot pop from an empty stack.\n";
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Function to peek at the top element of the stack
    int peek() {
        if (isEmpty()) {
            std::cerr << "Stack is empty!\n";
            return -1; // Returning -1 to indicate an error
        }
        return top->data;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to display the stack
    void display() {
        Node* current = top;
        std::cout << "Stack: ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    // Destructor to free up memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display(); // Stack: 30 20 10

    std::cout << "Top element is: " << stack.peek() << "\n"; // Top element is: 30

    stack.pop();
    std::cout << "After popping, top element is: " << stack.peek() << "\n"; // Top element is: 20

    stack.display(); // Stack: 20 10

    stack.pop();
    stack.pop();
    stack.pop(); // Attempting to pop from an empty stack

    return 0;
}
