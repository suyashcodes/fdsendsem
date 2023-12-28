#include <iostream>

// Node structure for the circular linked list
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

namespace clist {
    // Function to display the circular linked list
    void displayList(Node* head) {
        if (head == nullptr) {
            return;
        }

        Node* current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);

        std::cout << std::endl;
    }

    // Function to insert a node at the beginning
    Node* insertAtBeginning(Node* head, int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            newNode->next = newNode; // Circular link to itself
            return newNode;
        }

        newNode->next = head->next;
        head->next = newNode;
        return head;
    }

    // Function to insert a node at the end
    Node* insertAtEnd(Node* head, int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            newNode->next = newNode; // Circular link to itself
            return newNode;
        }

        Node *current=head;
        while (current->next!=head){
            current=current->next;
        }
        current->next=newNode;
        newNode->next=head;
        
        return head;
    }

    // Function to insert a node at a specific position
    Node* insertAtPosition(Node* head, int value, int position) {
        if (position <= 0) {
            return insertAtBeginning(head, value);
        }

        Node* newNode = new Node(value);
        Node* current = head;
        int index = 0;

        while (current->next != head && index < position - 1) {
            current = current->next;
            index++;
        }

        newNode->next = current->next;
        current->next = newNode;
        return head;
    }

    // Function to delete a node at the beginning
    Node* deleteAtBeginning(Node* head) {
        if (head == nullptr || head->next == head) {
            delete head;
            return nullptr;
        }
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }

        Node* temp = head;
        head = temp->next;
        current->next=temp->next;
        delete temp;
        return head;
    }

    // Function to delete a node at the end
    Node* deleteAtEnd(Node* head) {
        if (head == nullptr || head->next == head) {
            delete head;
            return nullptr;
        }

        Node* current = head;
        while (current->next->next != head) {
            current = current->next;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        return head;
    }

    // Function to delete a node at a specific position
    Node* deleteAtPosition(Node* head, int position) {
        if (head == nullptr || head->next == head) {
            delete head;
            return nullptr;
        }

        if(position==0){
            Node* temp = deleteAtBeginning(head);
            return temp;
        }

        Node* current = head;
        int index = 0;

        while (current->next->next != head && index < position - 1) {
            current = current->next;
            index++;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        return head;
    }

    // Function to clean up the circular linked list
    void cleanUpList(Node* head) {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
}

int main() {
    using namespace clist;

    Node* head = nullptr;

    // Insert at the beginning
    head = insertAtBeginning(head, 1);
    displayList(head);
    head = insertAtBeginning(head, 25);
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

    // Clean up the circular linked list
    cleanUpList(head);

    return 0;
}
