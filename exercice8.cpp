#include <iostream>
#include <fstream>
using namespace std;

class Fichier {
private:
    char* data;   // Pointer to dynamically allocated memory
    int length;   // Length of the allocated memory in bytes

public:
    // Constructor
    Fichier() : data(nullptr), length(0) {}

    // Method to allocate memory
    void Creation(int len) {
        length = len; // Set length
        data = new char[length]; // Allocate memory for 'len' bytes
    }

    // Method to fill the allocated memory with arbitrary data
    void Remplit() {
        if (data) { // Ensure memory is allocated
            for (int i = 0; i < length; i++) {
                data[i] = 'A' + (i % 26); // Fill with letters A-Z
            }
        }
    }

    // Method to display the contents of the allocated memory
    void Affiche() {
        if (data) { // Ensure memory is allocated
            for (int i = 0; i < length; i++) {
                cout << data[i]; // Print each character
            }
            cout << endl; // New line after displaying all characters
        }
    }

    // Destructor to free allocated memory
    ~Fichier() {
        delete[] data; // Free the allocated memory
    }
};

int main() {
    Fichier fichier; // Create an object of Fichier

    int size;
    cout << "Enter the size of the file (in bytes): ";
    cin >> size;

    fichier.Creation(size); // Allocate memory
    fichier.Remplit();       // Fill the memory with data
    cout << "Contents of the file: ";
    fichier.Affiche();      // Display the contents

    return 0;               // Program ends
}
