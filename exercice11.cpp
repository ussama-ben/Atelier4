#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Traitement {
private:
    vector<int> nombres;

    void showRecursif(int index) {
        if (index >= nombres.size()) {
            return;
        }
        cout << nombres[index] << " ";
        showRecursif(index + 1);
    }

public:
    Traitement() {
        nombres.reserve(15);
    }

    void Initialise() {
        nombres.clear();
        int nombre;

        cout << "Veuillez saisir 15 nombres entiers pairs non nuls:" << endl;

        while (nombres.size() < 15) {
            cout << "Entrez le nombre " << nombres.size() + 1 << "/15: ";

            if (cin >> nombre) {
                if (nombre != 0 && nombre % 2 == 0) {
                    nombres.push_back(nombre);
                } else {
                    cout << "Erreur: Le nombre doit être pair et non nul!" << endl;
                }
            } else {
                cout << "Erreur: Veuillez entrer un nombre entier valide!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }

    void show() {
        cout << "Elements du vecteur: ";
        showRecursif(0);
        cout << endl;
    }

    friend double moyenne(const Traitement& t);
    friend double median(const Traitement& t);
};

double moyenne(const Traitement& t) {
    if (t.nombres.empty()) return 0;

    double somme = 0;
    for (int nombre : t.nombres) {
        somme += nombre;
    }
    return somme / t.nombres.size();
}

double median(const Traitement& t) {
    if (t.nombres.empty()) return 0;

    vector<int> copie = t.nombres;
    sort(copie.begin(), copie.end());

    if (copie.size() % 2 != 0) {
        return copie[copie.size() / 2];
    } else {
        int index = copie.size() / 2;
        return (copie[index - 1] + copie[index]) / 2.0;
    }
}

int main() {
    Traitement t;
    t.Initialise();
    t.show();
    cout << "Moyenne: " << moyenne(t) << endl;
    cout << "Médiane: " << median(t) << endl;
    return 0;
}
