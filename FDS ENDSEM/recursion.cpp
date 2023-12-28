#include <iostream>

// Recursive function for calculating factorial
int recursive_factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * recursive_factorial(n - 1);
    }
}

// Non-recursive function for calculating factorial
int non_recursive_factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Recursive function for generating Fibonacci series
int recursive_fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
    }
}

// Non-recursive function for generating Fibonacci series
int non_recursive_fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, temp;
    for (int i = 2; i <= n; ++i) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    int n = 5;

    // Factorial
    std::cout << "Recursive Factorial of " << n << ": " << recursive_factorial(n) << std::endl;
    std::cout << "Non-recursive Factorial of " << n << ": " << non_recursive_factorial(n) << std::endl;

    // Fibonacci series
    std::cout << "\nRecursive Fibonacci series up to " << n << " terms:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << recursive_fibonacci(i) << " ";
    }

    std::cout << "\n\nNon-recursive Fibonacci series up to " << n << " terms:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << non_recursive_fibonacci(i) << " ";
    }

    return 0;
}
