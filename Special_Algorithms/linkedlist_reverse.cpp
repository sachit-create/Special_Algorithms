#include <iostream>
using namespace std;

class Node{
  public:
    int value;
    Node* next;

    Node(int val){
        value = val;
        next = NULL;
    }
};

class LinkedList{
    public:
        Node* head;
      LinkedList(){
        head = NULL;
      }

      void insert(int val){
         Node* newn = new Node(val);
         newn->next = head;
         head = newn;
      }

     void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->value << " --- ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
     } 

     void reverse(){
        Node* prevptr = NULL;
        Node* current = head;

        while(current!=NULL){
            Node* nextptr = current->next;
            current->next = prevptr;
            prevptr = current;
            current = nextptr;
        }
        head = prevptr;
     }
};

int main(){
    LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    ll.insert(6);
    ll.display();
    ll.reverse();
    ll.display();
    return 0;
}