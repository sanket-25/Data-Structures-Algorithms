#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to insert a node at the beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Function to insert a node at the end
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Function to insert a node at a specific position
    void insertAtPosition(int data, int position) {
        if (position < 0) {
            std::cerr << "Invalid position!\n";
            return;
        }

        Node* newNode = new Node(data);
        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        for (int i = 0; i < position - 1 && current != nullptr; i++) {
            current = current->next;
        }

        if (current == nullptr) {
            std::cerr << "Position out of bounds!\n";
            delete newNode;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Function to delete a node with a specific value
    void deleteNode(int data) {
        if (head == nullptr) {
            std::cerr << "List is empty!\n";
            return;
        }

        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != data) {
            current = current->next;
        }

        if (current->next == nullptr) {
            std::cerr << "Node not found!\n";
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // Function to display the list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr\n";
    }

    // Destructor to free up memory
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtBeginning(5);
    list.insertAtPosition(15, 2);

    std::cout << "Linked List: ";
    list.display();

    list.deleteNode(15);
    std::cout << "After deleting 15: ";
    list.display();

    list.deleteNode(5);
    std::cout << "After deleting 5: ";
    list.display();

    list.deleteNode(100); // Trying to delete a non-existent node

    return 0;
}
