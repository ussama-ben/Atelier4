#include <iostream>
using namespace std ;

class test {
    private : 
    static int count ;
    public : 
    void call();
    static int countcall();

};
int test :: count = 0 ;
void test :: call(){
    count++;
    cout<<"la fonction call a ete appele . "<<endl;

}
int test :: countcall(){
    return count;

}
int main(){
    test M ;

    M.call();
    M.call();
    M.call();
    cout<<"le nombre d'appel de fonction call est : "<<test::countcall()<<endl;
    return 0;
}