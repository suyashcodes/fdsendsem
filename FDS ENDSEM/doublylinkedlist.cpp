#include <iostream>

// Node structure for the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

    // Function to display the doubly linked list
    void displayList(Node* head) {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Function to insert a node at the beginning
    Node* insertAtBeginning(Node* head, int value) {
        Node* newNode = new Node(value);
        if (head != nullptr) {
            newNode->next = head;
            head->prev = newNode;
        }
        return newNode;
    }

    // Function to insert a node at the end
    Node* insertAtEnd(Node* head, int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            return newNode; // If the list is empty, newNode becomes the head
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        return head; // Return the unchanged head
    }

    // Function to insert a node at a specific position
    Node* insertAtPosition(Node* head, int value, int position) {
        if (position <= 0) {
            return insertAtBeginning(head, value);
        }

        Node* newNode = new Node(value);
        Node* current = head;
        int index = 0;

        while (current != nullptr && index < position - 1) {
            current = current->next;
            index++;
        }

        if (current != nullptr) {
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != nullptr) {
                current->next->prev = newNode;
            }
            current->next = newNode;
        }

        return head; // Return the unchanged head if position is out of bounds
    }

    // Function to delete a node at the beginning
    Node* deleteAtBeginning(Node* head) {
        if (head == nullptr) {
            return nullptr; // Return nullptr if the list is already empty
        }
        Node* newHead = head->next;
        if (newHead != nullptr) {
            newHead->prev = nullptr;
        }
        delete head;
        return newHead; // Return the new head
    }

    // Function to delete a node at the end
    Node* deleteAtEnd(Node* head) {
        if (head == nullptr) {
            return nullptr; // Return nullptr if the list is already empty
        }
        if (head->next == nullptr) {
            delete head;
            return nullptr; // Return nullptr if there's only one node in the list
        }
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
        return head; // Return the unchanged head
    }

    // Function to delete a node at a specific position
    Node* deleteAtPosition(Node* head, int position) {
        if (head == nullptr) {
            return nullptr; // Return nullptr if the list is already empty
        }
        if (position <= 0) {
            return deleteAtBeginning(head);
        }
        Node* current = head;
        int index = 0;

        while (current != nullptr && index < position) {
            current = current->next;
            index++;
        }

        if (current != nullptr) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            delete current;
        }

        return head; // Return the unchanged head if position is out of bounds
    }


int main() {

    Node* head = nullptr;

    // Insert at the beginning
    head = insertAtBeginning(head, 1);
    displayList(head);

    // Insert at the end
    head = insertAtEnd(head, 2);
    displayList(head);

    // Insert at a specific position
    head = insertAtPosition(head, 3, 1);
    displayList(head);

    // Delete at the beginning
    head = deleteAtBeginning(head);
    displayList(head);

    // Delete at the end
    head = deleteAtEnd(head);
    displayList(head);

    // Delete at a specific position
    head = deleteAtPosition(head, 0);
    displayList(head);

    return 0;
}
