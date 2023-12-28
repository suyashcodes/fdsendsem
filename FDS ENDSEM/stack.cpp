#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow: Cannot push element, stack is full." << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed to the stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow: Cannot pop element, stack is empty." << endl;
            return;
        }
        int poppedValue = arr[top--];
        cout << poppedValue << " popped from the stack." << endl;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1; // Assuming -1 as an indicator of an empty stack
        }
        return arr[top];
    }
};

int main() {
    Stack stack;

    stack.push(5);
    stack.push(10);
    stack.push(15);

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();
    stack.pop();
    stack.pop();

    cout << "Top element after popping all elements: " << stack.peek() << endl;

    return 0;
}
