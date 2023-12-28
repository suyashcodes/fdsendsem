#include <iostream>

// Node structure for the linked list
struct Node {
    int data;
    int priority;
    Node* next;

    Node(int d, int p) : data(d), priority(p), next(nullptr) {}
};

class PriorityQueue {
private:
    Node* front;

public:
    PriorityQueue() : front(nullptr) {}

    // Function to insert an element with priority into the priority queue
    void enqueue(int data, int priority) {
        Node* newNode = new Node(data, priority);

        // If the queue is empty or the new element has higher priority, insert at the front
        if (front == nullptr || priority > front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            // Find the position to insert the new element based on priority
            Node* temp = front;
            while (temp->next != nullptr && temp->next->priority >= priority) {
                temp = temp->next;
            }

            // Insert the new element after the found position
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Function to remove and return the highest-priority element from the priority queue
    int dequeue() {
        if (isEmpty()) {
            std::cout << "PriorityQueue is empty.\n";
            return -1;  // or throw an exception
        }

        Node* temp = front;
        int removedData = temp->data;

        front = front->next;
        delete temp;

        return removedData;
    }

    // Function to check if the priority queue is empty
    bool isEmpty() const {
        return front == nullptr;
    }
};

int main() {
    PriorityQueue priorityQueue;

    priorityQueue.enqueue(30, 3);
    priorityQueue.enqueue(10, 1);
    priorityQueue.enqueue(50, 5);
    priorityQueue.enqueue(20, 2);
    priorityQueue.enqueue(200, 2);

    while (!priorityQueue.isEmpty()) {
        std::cout << priorityQueue.dequeue() << " ";
    }
    std::cout << std::endl;

    return 0;
}
