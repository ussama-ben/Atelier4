#include <iostream>
using namespace std;

class Pile {
private:
    int* elements; // Array to hold stack elements
    int size;  // Maximum size of the stack
    int top;   // Index of the top element

public:
    Pile(int size); // Constructor
    ~Pile(); // Destructor
    void push(int valeur); // Method to add an element
    int pop(); // Method to remove an element
    bool estVide(); // Method to check if the stack is empty
};

// Constructor to initialize stack
Pile::Pile(int size) {
    this->size = size;
    elements = new int[size]; // Dynamic memory allocation
    top = -1; // Indicates that the stack is empty
}

// Destructor to clean up memory
Pile::~Pile() {
    delete[] elements; // Free the allocated memory
}

// Method to add an element to the stack
void Pile::push(int valeur) {
    if (top < size - 1) {
        elements[++top] = valeur; // Increment the top index and add value
    } else {
        cout << "La pile est pleine !" << endl; // Handle stack overflow
    }
}

// Method to remove an element from the stack
int Pile::pop() {
    if (!estVide()) {
        return elements[top--]; // Return top value and decrement the top index
    } else {
        cout << "La pile est vide !" << endl; // Handle stack underflow
        return -1; // Error value
    }
}

// Method to check if the stack is empty
bool Pile::estVide() {
    return top == -1; // Returns true if the stack is empty
}

// Main function to test the stack
int main() {
    Pile p1(5); // Create a stack with size 5
    p1.push(10);
    p1.push(20);
    p1.push(30);

    cout << "Dépiler: " << p1.pop() << endl; // Display the top element
    cout << "Dépiler: " << p1.pop() << endl; // Display the next element
    cout << "Dépiler: " << p1.pop() << endl; // Display the last element
    cout << "Dépiler: " << p1.pop() << endl; // Try to pop from an empty stack

    return 0; // Exit the program
}
