//linked lists

#include <iostream>
using namespace std;


// Ejemplo de linked list



class linkedList{
    private:
        struct node{
            int data;
            node* next;
        };
        
        node* head;
        node* tail;
        node* temp;
    public:


        linkedList(){
            head = NULL;
            tail = NULL;
            temp = NULL;
        };


        void insert(int data){
            node* n = new node;
            n->next = NULL;
            n->data = data;

            if(tail != NULL){
                tail->next = n;
                tail = n;
            }
            else{
                head = n;
                tail = n;
            }

        }   
        int pop(){
            int valor = tail->data;

            temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;

            return valor;
        };
        void printList(){
            temp = head;
            while(temp != NULL){
                cout << temp->data << endl;
                temp = temp->next;
            }
        };

        void peek(){
            cout << tail->data << endl;
        };

        void peekhead(){
            cout << head->data << endl;
        };

        bool isEmpty(){
            if(head == NULL){
                return true;
            } else{
                return false;
            }
        };

        int size(){
            int count = 0;
            temp = head;
            while(temp != NULL){
                count++;
                temp = temp->next;
            }
            return count;
        };
};



int main(){

    linkedList lista1;
    if(lista1.isEmpty()){
        cout << "Lista vacia" << endl;
    }
    lista1.insert(26);
    lista1.insert(5);
    lista1.insert(9);


    cout << "Lista impresa" << endl;
    lista1.printList();
    cout << "Peek Tail y Head" << endl;
    lista1.peek();
    lista1.peekhead();

    cout << "Lista impresa despues de pop"<< endl;
    int valor = lista1.pop();
    lista1.printList();
    cout << "Valor de pop: " << valor << endl;

    int tamaño = lista1.size();
    cout << "Size de la lista: " << tamaño << endl;

}