#include <iostream>
using namespace std;

class complexe {
private:
    int rel, img;

public:
    complexe();
    complexe(int x, int y);
    complexe(const complexe& c);

    void afficher();
    void setValues(int x, int y);
    
    // Overloaded operators
    complexe operator+(const complexe& other);
    complexe operator-(const complexe& other);
    complexe operator*(const complexe& other);
    complexe operator/(const complexe& other);
    bool operator==(const complexe& other);
};

complexe::complexe() : rel(0), img(0) {}

complexe::complexe(int x, int y) : rel(x), img(y) {}

complexe::complexe(const complexe& c) : rel(c.rel), img(c.img) {}

void complexe::setValues(int x, int y) {
    rel = x;
    img = y;
}

void complexe::afficher() {
    cout << rel << " + i" << img;
}

complexe complexe::operator+(const complexe& other) {
    return complexe(rel + other.rel, img + other.img);
}

complexe complexe::operator-(const complexe& other) {
    return complexe(rel - other.rel, img - other.img);
}

complexe complexe::operator*(const complexe& other) {
    int realPart = (rel * other.rel) - (img * other.img);
    int imagPart = (rel * other.img) + (img * other.rel);
    return complexe(realPart, imagPart);
}

complexe complexe::operator/(const complexe& other) {
    int denominator = other.rel * other.rel + other.img * other.img; // (c^2 + d^2)
    if (denominator == 0) {
        throw invalid_argument("Division by zero in complex numbers");
    }
    int realPart = (rel * other.rel + img * other.img) / denominator;
    int imagPart = (img * other.rel - rel * other.img) / denominator;
    return complexe(realPart, imagPart);
}

bool complexe::operator==(const complexe& other) {
    return (rel == other.rel && img == other.img);
}

int main() {
    int realPart, imgPart, choice;
    complexe c1, c2;

    cout << "Enter the real and imaginary part of the first complex number:\n";
    cout << "Real part: ";
    cin >> realPart;
    cout << "Imaginary part: ";
    cin >> imgPart;
    c1.setValues(realPart, imgPart);

    cout << "\nEnter the real and imaginary part of the second complex number:\n";
    cout << "Real part: ";
    cin >> realPart;
    cout << "Imaginary part: ";
    cin >> imgPart;
    c2.setValues(realPart, imgPart);

    cout << "\nFirst complex number: ";
    c1.afficher();
    
    cout << "\nSecond complex number: ";
    c2.afficher();

    // Asking the user to choose an operation
    cout << "\nChoose an operation:\n";
    cout << "1. Sum\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Check Equality\n";
    cout << "Enter your choice (1/2/3/4/5): ";
    cin >> choice;

    complexe result;

    switch(choice) {
        case 1:
            result = c1 + c2;
            cout << "\n\nSum of the two complex numbers: ";
            result.afficher();
            break;
        case 2:
            result = c1 - c2;
            cout << "\n\nSubtraction of the two complex numbers: ";
            result.afficher();
            break;
        case 3:
            result = c1 * c2;
            cout << "\n\nMultiplication of the two complex numbers: ";
            result.afficher();
            break;
        case 4:
            try {
                result = c1 / c2;
                cout << "\n\nDivision of the two complex numbers: ";
                result.afficher();
            } catch (const invalid_argument& e) {
                cout << e.what() << endl;
            }
            break;
        case 5:
            if (c1 == c2) {
                cout << "\nThe two complex numbers are equal.";
            } else {
                cout << "\nThe two complex numbers are not equal.";
            }
            break;
        default:
            cout << "Invalid choice!";
            break;
    }

    return 0;
}
