#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow: Cannot enqueue element, queue is full." << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        arr[++rear] = value;
        cout << value << " enqueued to the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow: Cannot dequeue element, queue is empty." << endl;
            return;
        }

        int dequeuedValue = arr[front++];
        cout << dequeuedValue << " dequeued from the queue." << endl;

        if (front > rear) {
            front = rear = -1; // Reset the queue when it becomes empty
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1; // Assuming -1 as an indicator of an empty queue
        }
        return arr[front];
    }
};

int main() {
    Queue queue;

    queue.enqueue(5);
    queue.enqueue(10);
    queue.enqueue(15);

    cout << "Front element: " << queue.peek() << endl;

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    cout << "Front element after dequeueing all elements: " << queue.peek() << endl;

    return 0;
}
