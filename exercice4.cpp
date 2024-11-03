#include <iostream>
#include <cmath>
using namespace std;

class vecteur3d {
private:
    float x;
    float y;
    float z;
public:
    vecteur3d();
    vecteur3d(float x, float y, float z);
    vecteur3d(const vecteur3d& c);

    void afficher() const;
    vecteur3d operator+(const vecteur3d& other);
    float operator*(const vecteur3d& other);
    bool operator==(const vecteur3d& other);
    float norme() const;
    vecteur3d normax(const vecteur3d& other) const;
    vecteur3d& normax_reference(vecteur3d& other) ;
    vecteur3d* normax_adresse(const vecteur3d* other) const;
};

vecteur3d::vecteur3d() : x(0), y(0), z(0) {}

vecteur3d::vecteur3d(float X, float Y, float Z) : x(X), y(Y), z(Z) {}

vecteur3d::vecteur3d(const vecteur3d& c) : x(c.x), y(c.y), z(c.z) {}

void vecteur3d::afficher() const {
    cout << "(" << x << "," << y << "," << z << ")" << endl;
}

vecteur3d vecteur3d::operator+(const vecteur3d& other) {
    return vecteur3d(x + other.x, y + other.y, z + other.z);
}

float vecteur3d::operator*(const vecteur3d& other) {
    return (x * other.x + y * other.y + z * other.z);
}

bool vecteur3d::operator==(const vecteur3d& other) {
    return (x == other.x && y == other.y && z == other.z);
}

float vecteur3d::norme() const {
    return std::sqrt(x * x + y * y + z * z);
}

vecteur3d vecteur3d::normax(const vecteur3d& other) const {
    return (this->norme() > other.norme()) ? *this : other;
}

vecteur3d* vecteur3d::normax_adresse(const vecteur3d* other) const {
    return (this->norme() > other->norme()) ? (vecteur3d*)this : (vecteur3d*)other;
}

vecteur3d& vecteur3d::normax_reference(vecteur3d& other) {
    return (this->norme() > other.norme()) ? *this : other;
}


int main() {
    vecteur3d v1(1, 5, 8);
    vecteur3d v2(3, 8, 9);

    cout << "v1: "; 
    v1.afficher();
    cout << "v2: "; 
    v2.afficher();

    vecteur3d sum = v1 + v2;
    cout << "La somme des deux vecteurs est : ";
    sum.afficher();

    float produit_scalaire = v1 * v2;
    cout << "Le produit scalaire des deux vecteurs est : " << produit_scalaire << endl;

    if (v1 == v2) {
        cout << "Les vecteurs v1 et v2 sont égaux." << endl;
    } else {
        cout << "Les vecteurs v1 et v2 ne sont pas égaux." << endl;
    }

    cout << "La norme de v1 est : " << v1.norme() << endl;
    cout << "La norme de v2 est : " << v2.norme() << endl;

    vecteur3d max_norm_vector = v1.normax(v2);
    cout << "Le vecteur avec la plus grande norme est : ";
    max_norm_vector.afficher();

    vecteur3d& max_norm_ref_vector = v1.normax_reference(v2);
    cout << "Le vecteur avec la plus grande norme (par référence) est : ";
    max_norm_ref_vector.afficher();

    vecteur3d* max_norm_addr_vector = v1.normax_adresse(&v2);
    cout << "Le vecteur avec la plus grande norme (par adresse) est : ";
    max_norm_addr_vector->afficher();

    return 0;
}
