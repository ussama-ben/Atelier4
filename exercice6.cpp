#include <iostream> 
using namespace std ;

class point {
    private :
    float x;
    float y ;
    public :
    point(float x , float y):x(x),y(y){}
    void deplace(float dx , float dy){
        x+=dx;
        y+=dy;
    }
    void afficher(){
        cout<<"coordonnee du points ("<<x<<","<<y<<")"<<endl;
    }
};
int main(){

    point p(2.2,3.6);
    p.afficher();

    p.deplace(1.2,5.4);
    p.afficher();
    return 0 ; 

}