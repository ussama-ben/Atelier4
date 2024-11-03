#include <iostream>
using namespace std ;

class Animal {
    protected : 
    string Name ;
    int Age ;
    public :
    void set_value(string N , int A){
        Name = N ;
        Age = A ;
     };
};

class Zebre : public Animal{
    public :
    void afficher(){
        cout<<"le nom de Zebre : "<<Name<<"et Age : "<<Age<<endl;
        cout<<"l'origine de Zebre est Savane"<<endl;
    }
};

class dauphin : public Animal {
    public : 
      void afficher(){
        cout<<"le nom de dauphin : "<<Name<<"et Age : "<<Age<<endl;
        cout<<"l'origine de dauphin est ocean"<<endl;
    }
};

int main(){
    Zebre z1;
    dauphin d1 ;
    z1.set_value("allouch",5);
    z1.afficher();
    d1.set_value("breeze",4);
    d1.afficher();

    return 0 ;
}