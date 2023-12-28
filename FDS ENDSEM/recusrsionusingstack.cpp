#include <iostream>
#include <stack>

// Recursive function to calculate factorial
int recursive_factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * recursive_factorial(n - 1);
    }
}

// Recursive function using an explicit stack
int recursive_factorial_with_stack(int n) {
    std::stack<int> callStack;
    callStack.push(n);

    int result = 1;

    while (!callStack.empty()) {
        int current = callStack.top();
        callStack.pop();

        if (current > 1) {
            result *= current;
            callStack.push(current - 1);
        }
    }

    return result;
}

int recursive_factorial_with_stack(int n){
    std::stack<int> callstack;
    callstack.push(n);
    int result=1;
    while(!callstack.empty()){
        int current = callstack.top();
        callstack.pop();
        if(current>1){
        result*=current;
        callstack.push(current-1);
    }
    }
    return result;
}

int main() {
    int n = 5;

    // Calculate factorial using the original recursive function
    std::cout << "Recursive Factorial of " << n << ": " << recursive_factorial(n) << std::endl;

    // Calculate factorial using the recursive function with an explicit stack
    std::cout << "Recursive Factorial with Stack of " << n << ": " << recursive_factorial_with_stack(n) << std::endl;
    return 0;
}
