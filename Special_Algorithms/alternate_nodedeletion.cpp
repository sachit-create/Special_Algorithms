#include <iostream>
using namespace std;

class Node{
    public:
     int value;
     Node* link;

     Node(int val){
        value = val;
        link = NULL;
     }
};

class Linkedlist{
    public:
      Node* head = NULL;

      void insert(int val){
         Node* new_node = new Node(val);
         new_node->link = head;
         head = new_node;
      }

      void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->value << " --- ";
            temp = temp->link;
        }
        cout << "NULL" << endl;
      }
    
      void alt_ele_dlt() {
    if (head == NULL) {
        return; // If the list is empty, there's nothing to do
    }

    Node *current = head;

    // If there's only one node, no alternates to delete
    if (current->link == NULL) {
        return;
    }

    while (current != NULL && current->link != NULL) {
        // Node to be deleted is current->link
        Node *temp = current->link; // Save the node to delete
        current->link = temp->link; // Skip the node to delete
        delete temp; // Delete the node

        // Move to the next node
        current = current->link;
    }
}

};

int main(){
    Linkedlist ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    ll.display();
    ll.alt_ele_dlt();
    ll.display();
    return 0;
}