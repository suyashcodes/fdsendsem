#include <iostream>

// Node structure for the singly linked list
struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

// Function to display the linked list
void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Function to search for an element by value
bool searchByValue(Node* head, int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true; // Element found
        }
        current = current->next;
    }
    return false; // Element not found
}

// Function to search for an element by position
int searchByPosition(Node* head, int position) {
    Node* current = head;
    int index = 0;
    while (current != nullptr && index < position) {
        current = current->next;
        index++;
    }
    if (current != nullptr) {
        return current->data; // Return data at the specified position
    } else {
        return -1; // Position out of bounds
    }
}

// Function to insert a node at the beginning
Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    return newNode; // Return the new head
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
    return head; // Return the unchanged head
}

// Function to insert a node at a specific position
Node* insertAtPosition(Node* head, int value, int position) {
    if (position == 0) {
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
    if (position == 0) {
        return deleteAtBeginning(head);
    }
    Node* current = head;
    int index = 0;
    while (current != nullptr && index < position - 1) {
        current = current->next;
        index++;
    }
    if (current != nullptr && current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
    return head; // Return the unchanged head if position is out of bounds
}

// Function to modify a node's value by position
void modifyByPosition(Node* head, int position, int newValue) {
    Node* current = head;
    int index = 0;
    while (current != nullptr && index < position) {
        current = current->next;
        index++;
    }
    if (current != nullptr) {
        current->data = newValue; // Modify the value at the specified position
    }
}

void displayMenu() {
    std::cout << "\n--- Linked List Operations Menu ---\n";
    std::cout << "1. Display the Linked List\n";
    std::cout << "2. Insert at the Beginning\n";
    std::cout << "3. Insert at the End\n";
    std::cout << "4. Insert at a Specific Position\n";
    std::cout << "5. Delete at the Beginning\n";
    std::cout << "6. Delete at the End\n";
    std::cout << "7. Delete at a Specific Position\n";
    std::cout << "8. Search by Value\n";
    std::cout << "9. Search by Position\n";
    std::cout << "10. Modify by Position\n";
    std::cout << "0. Exit\n";
    std::cout << "----------------------------------\n";
}

int main() {
    Node* head = nullptr;

    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Linked List: ";
                displayList(head);
                break;
            case 2:
                int insertValue;
                std::cout << "Enter the value to insert at the beginning: ";
                std::cin >> insertValue;
                head = insertAtBeginning(head, insertValue);
                break;
            case 3:
                std::cout << "Enter the value to insert at the end: ";
                std::cin >> insertValue;
                head = insertAtEnd(head, insertValue);
                break;
            case 4:
                int insertPosition;
                std::cout << "Enter the value to insert: ";
                std::cin >> insertValue;
                std::cout << "Enter the position to insert at: ";
                std::cin >> insertPosition;
                head = insertAtPosition(head, insertValue, insertPosition);
                break;
            case 5:
                head = deleteAtBeginning(head);
                break;
            case 6:
                head = deleteAtEnd(head);
                break;
            case 7:
                int deletePosition;
                std::cout << "Enter the position to delete: ";
                std::cin >> deletePosition;
                head = deleteAtPosition(head, deletePosition);
                break;
            case 8:
                int searchValue;
                std::cout << "Enter the value to search: ";
                std::cin >> searchValue;
                if (searchByValue(head, searchValue)) {
                    std::cout << searchValue << " found in the list.\n";
                } else {
                    std::cout << searchValue << " not found in the list.\n";
                }
                break;
            case 9:
                int searchPosition;
                std::cout << "Enter the position to search: ";
                std::cin >> searchPosition;
                int valueAtPosition = searchByPosition(head, searchPosition);
                if (valueAtPosition != -1) {
                    std::cout << "Value at position " << searchPosition << ": " << valueAtPosition << "\n";
                } else {
                    std::cout << "Position " << searchPosition << " is out of bounds.\n";
                }
                break;
            case 10:
                int modifyPosition, newValue;
                std::cout << "Enter the position to modify: ";
                std::cin >> modifyPosition;
                std::cout << "Enter the new value: ";
                std::cin >> newValue;
                modifyByPosition(head, modifyPosition, newValue);
                break;
            case 11:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 11);

    // Clean up: delete remaining nodes in the linked list
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}