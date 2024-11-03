#include <iostream>
#include <string>
using namespace std;

// Classe de base Personne
class Personne {
protected:
    string nom;
    string prenom;
    string date_naissance;

public:
    // Constructeur de la classe Personne
    Personne(string nom, string prenom, string date_naissance) 
        : nom(nom), prenom(prenom), date_naissance(date_naissance) {}

    // Méthode virtuelle pour l'affichage des données de la personne
    virtual void Afficher() const {
        cout << "Nom: " << nom << ", Prénom: " << prenom << ", Date de Naissance: " << date_naissance << endl;
    }
};

// Classe dérivée Employe
class Employe : public Personne {
protected:
    double salaire;

public:
    // Constructeur de la classe Employe
    Employe(string nom, string prenom, string date_naissance, double salaire) 
        : Personne(nom, prenom, date_naissance), salaire(salaire) {}

    // Accesseur pour le salaire
    double getSalaire() const {
        return salaire;
    }

    // Redéfinition de la méthode Afficher
    void Afficher() const override {
        Personne::Afficher();
        cout << "Salaire: " << salaire << " EUR" << endl;
    }
};

// Classe dérivée Chef
class Chef : public Employe {
protected:
    string service;

public:
    // Constructeur de la classe Chef
    Chef(string nom, string prenom, string date_naissance, double salaire, string service) 
        : Employe(nom, prenom, date_naissance, salaire), service(service) {}

    // Accesseur pour le service
    string getService() const {
        return service;
    }

    // Redéfinition de la méthode Afficher
    void Afficher() const override {
        Employe::Afficher();
        cout << "Service: " << service << endl;
    }
};

// Classe dérivée Directeur
class Directeur : public Chef {
protected:
    string societe;

public:
    // Constructeur de la classe Directeur
    Directeur(string nom, string prenom, string date_naissance, double salaire, string service, string societe) 
        : Chef(nom, prenom, date_naissance, salaire, service), societe(societe) {}

    // Accesseur pour la société
    string getSociete() const {
        return societe;
    }

    // Redéfinition de la méthode Afficher
    void Afficher() const override {
        Chef::Afficher();
        cout << "Société: " << societe << endl;
    }
};

int main() {
    // Création d'un objet Directeur
    Directeur op("Durand", "Jean", "01/01/1980", 85000, "Informatique", "TechCorp");
    
    // Appel de la méthode Afficher
    op.Afficher();

    return 0;
}
