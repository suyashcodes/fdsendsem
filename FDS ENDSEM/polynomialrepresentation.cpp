#include <iostream>

class Node {
public:
    int coefficient;
    int exponent;
    Node* next;

    // Constructor
    Node(int coeff, int exp) : coefficient(coeff), exponent(exp), next(nullptr) {}
};

// void addTerm(Node*& poly, int coeff, int exp) {
//     // Node* newTerm = new Node(coeff, exp);
//     // newTerm->next = poly;
//     // poly = newTerm;

//     Node* temp = poly;
//     while(temp->next!=nullptr){
//         temp=temp->next;
//     }
//     Node* newTerm = new Node(coeff, exp);
//     temp->next = newTerm;
// }
void addTerm(Node*& poly, int coeff, int exp) {
    Node* newTerm = new Node(coeff, exp);

    if (!poly) {
        // If the polynomial is empty, set poly to the new term
        poly = newTerm;
    } else {
        // If the polynomial is not empty, find the last node and append the new term
        Node* temp = poly;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newTerm;
    }
}

void displayPolynomial(Node* poly) {
    if (!poly) {
        std::cout << "Polynomial is empty." << std::endl;
        return;
    }

    Node* current = poly;
    while (current) {
        std::cout << current->coefficient << "x^" << current->exponent;
        current = current->next;
        if (current) {
            std::cout << " + ";
        }
    }
    std::cout << std::endl;
}

int main() {
    // Creating the linked list for the polynomial 3x^4 + 2x^2 - 7x + 1
    Node* polynomial = nullptr;

    // Adding terms to the polynomial
    addTerm(polynomial, 1, 0);
    addTerm(polynomial, -7, 1);
    addTerm(polynomial, 2, 2);
    addTerm(polynomial, 3, 4);

    // Displaying the polynomial
    displayPolynomial(polynomial);
    return 0;
}
