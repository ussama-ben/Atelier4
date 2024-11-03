#include <iostream> 
using namespace std ;

struct node {
    int data ;
    node* next;
};

class liste{
    private :
    node* head;
    public : 
    liste() : head(nullptr){}
    
    ~liste(){
        while(head != nullptr){
            node* temp = head ;
            head = head->next;
            delete temp ;
        }
    }
    void addbegin(int value){
        node* new_node= new node ;
        new_node->data = value;
        new_node -> next = head;
        head = new_node ;
        }
    
    void deletebegin(){
        if(head== NULL){
            cout<<"empty"<<endl;

     }else{
        node* first_node =head;
        head= first_node->next;
        delete(first_node);
     }
    }
    void display(){
        node* temp;
        if(head== NULL){cout<<"list empty"<<endl;
        
        }else{
            temp = head ;
            while(temp!=NULL){

                cout<<temp->data<<endl;
                temp = temp->next;
            }
        }
     }
    
};

int main(){

    liste M1;
    M1.addbegin(15);
    M1.addbegin(2);
    M1.addbegin(6);

    M1.display();
    return 0 ;
    

}