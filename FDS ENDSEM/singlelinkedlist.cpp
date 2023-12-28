#include <iostream>
using namespace std;
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
void searchByValue(Node* head, int value) {
    Node* current = head;
    int i=0;
    while (current != nullptr) {
        if (current->data == value) {
            cout<<"\nElement found at : "<<i<<endl; // Element found
            return;////////////////////note here
        }
        current = current->next;
        i++;
    }
    cout<<"\nElement doesnt found: "<<endl; // Element found
}

// Function to search for an element by position
void searchByPosition(Node* head, int position) {
    Node* current = head;
    int index = 0;
    while (current != nullptr && index < position) {
        current = current->next;
        index++;
    }
    if (current != nullptr) {
        cout<<"\nelement at position "<<position<<" is "<<current->data<<endl; // Return data at the specified position
    } else {
        cout<<"\nPosition out of bounds\n"; // Position out of bounds
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
    return head;
}

Node* addNodeAfterPosition(Node* head, int position, int value) {
    Node* newNode = new Node(value);
    
    if (position < 0) {
        std::cout << "Invalid position. No node added.\n";
        return head;
    }
    if (position == 0) {
        newNode->next = head->next;
        head->next = newNode;
        return head;
    }
    Node* current = head;
    int index = 0;
    while (current != nullptr && index < position) {
        current = current->next;
        index++;
    }
    if (current != nullptr) {
        newNode->next = current->next;
        current->next = newNode;
    } else {
        std::cout << "Position out of bounds. No node added.\n";
    }
    return head;
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

void count(Node* head){
    Node* temp =head;
    int cnt=0;
    while(temp!=nullptr){
        temp=temp->next;
        cnt++;
    }
    cout<<"\nUOMBER OF ELEMENT IS : "<<cnt<<endl;
}



int main() {
    Node* head = nullptr;
                head = insertAtBeginning(head, 32);
                displayList(head);
                head = insertAtEnd(head, 55);
                displayList(head);
                head = insertAtPosition(head, 45, 1);
                displayList(head);
                head = addNodeAfterPosition(head,0,123);
                displayList(head);
                // head = deleteAtBeginning(head);
                // displayList(head);

                // head = deleteAtEnd(head);
                // displayList(head);
                // head = deleteAtPosition(head, 3);
                // displayList(head);
                searchByValue(head,123);
                displayList(head);
                searchByPosition(head,2);
                displayList(head);
                modifyByPosition(head, 2, 22);
                displayList(head);

                count(head);
                // modifyByPosition(head, modifyPosition, newValue);
    

    return 0;
}