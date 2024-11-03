#include <iostream>
#include <string>
using namespace std;

string obtenirNomMois(const string& mois) {
    if (mois == "01") return "janvier";
    if (mois == "02") return "février";
    if (mois == "03") return "mars";
    if (mois == "04") return "avril";
    if (mois == "05") return "mai";
    if (mois == "06") return "juin";
    if (mois == "07") return "juillet";
    if (mois == "08") return "août";
    if (mois == "09") return "septembre";
    if (mois == "10") return "octobre";
    if (mois == "11") return "novembre";
    if (mois == "12") return "décembre";
    return "Mois inconnu";
}

string formaterJour(const string& jour) {
    if (jour == "01") return "1er";
    return jour;
}

void extraireDateHeure(const string& chaine) {
    if (chaine.length() != 12) {
        cout << "Erreur : La chaîne doit contenir exactement 12 caractères" << endl;
        return;
    }
    
    string jour = chaine.substr(0, 2);
    string mois = chaine.substr(2, 2);
    string annee = chaine.substr(4, 4);
    string heure = chaine.substr(8, 2);
    string minutes = chaine.substr(10, 2);
    
    cout << formaterJour(jour) << " " << obtenirNomMois(mois) << " " << annee << " à " 
         << heure << "h" << minutes << endl;
}

int main() {
    string dateTest;
    
    cout << "Veuillez entrer une chaine de 12 caracteres (JJMMAAAAHHNN) : ";
    cin >> dateTest;
    
    extraireDateHeure(dateTest);
    
    return 0;
}
