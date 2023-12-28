#include <iostream>
#include <cstdlib> // for malloc

class Node
{
public:
    int coefficient;
    int exponent;
    Node *next;

    // Constructor
    Node(int coeff, int exp) : coefficient(coeff), exponent(exp), next(nullptr) {}
};

void polyadd(Node *poly1, Node *poly2, Node *poly)
{
    while (poly1->next && poly2->next)
    {
        if (poly1->exponent > poly2->exponent)
        {
            poly->exponent = poly1->exponent;
            poly->coefficient = poly1->coefficient;
            poly1 = poly1->next;
        }
        else if (poly1->exponent < poly2->exponent)
        {
            poly->exponent = poly2->exponent;
            poly->coefficient = poly2->coefficient;
            poly2 = poly2->next;
        }
        else
        {
            poly->exponent = poly1->exponent;
            poly->coefficient = poly1->coefficient + poly2->coefficient;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        // Dynamically create new node
        poly->next = new Node(0, 0);
        poly = poly->next;
        poly->next = nullptr;
    }

    while (poly1->next || poly2->next)
    {
        if (poly1->next)
        {
            poly->exponent = poly1->exponent;
            poly->coefficient = poly1->coefficient;
            poly1 = poly1->next;
        }
        if (poly2->next)
        {
            poly->exponent = poly2->exponent;
            poly->coefficient = poly2->coefficient;
            poly2 = poly2->next;
        }

        // Dynamically create new node
        poly->next = new Node(0, 0);
        poly = poly->next;
        poly->next = nullptr;
    }
}
void addTerm(Node *&poly, int coeff, int exp)
{
    Node *newTerm = new Node(coeff, exp);

    if (!poly)
    {
        poly = newTerm;
    }
    else
    {
        Node *temp = poly;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newTerm;
    }
}

void displayPolynomial(Node *poly)
{
    if (!poly)
    {
        std::cout << "Polynomial is empty." << std::endl;
        return;
    }

    Node *current = poly;
    while (current)
    {
        std::cout << current->coefficient << "x^" << current->exponent;
        current = current->next;
        if (current)
        {
            std::cout << " + ";
        }
    }
    std::cout << std::endl;
}

// Provided polyadd function

int main()
{
    // Creating the linked list for the polynomial 3x^4 + 2x^2 - 7x + 1
    Node *polynomial1 = nullptr;
    addTerm(polynomial1, 5, 2);
    addTerm(polynomial1, 4, 1);
    addTerm(polynomial1, 2, 0);

    // Creating the linked list for the polynomial 4x^3 + 2x^2 - 5
    Node *polynomial2 = nullptr;
    addTerm(polynomial2, -5, 1);
    addTerm(polynomial2, -5, 0);
    // Displaying the first polynomial
    std::cout << "Polynomial 1: ";
    displayPolynomial(polynomial1);

    // Displaying the second polynomial
    std::cout << "Polynomial 2: ";
    displayPolynomial(polynomial2);

    // Adding the polynomials
    Node *result = new Node(0, 0);
    polyadd(polynomial1, polynomial2, result);

    // Displaying the result
    std::cout << "Resultant Polynomial: ";
    displayPolynomial(result);

    // Freeing memory
    delete polynomial1;
    delete polynomial2;
    delete result;

    return 0;
}
