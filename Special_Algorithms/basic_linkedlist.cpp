#include <iostream>
using namespace std;

class node{
    public:
      int value;
      node* link;

    node(int val): value(val) , link(nullptr){}
};

void insert(node* &head , int v){// for insert an element in start of linked list.
    node* new_node = new node(v);
    new_node->link = head;
    head = new_node;
}

int ll_length(node * head){ // calculate and return the length of the linked list.
    node * temp = head;
    int lcount = 0;
    while(temp!=NULL){
        lcount++;
        temp = temp->link;
    }
    return lcount;
}
void insertatposi(node* &head , int val , int posi){// for insertion of an element in a linked list at a posi.
    if(posi<0 || posi>ll_length(head)){ // check that posi is not out of the bound.
       cout << "position not found !" << endl;
       return;
    }

    if(posi==0){
       insert(head,val);
       return;
    }

    node* new_node = new node(val);
    node* temp = head;
    int currentcount = 0;
    while(currentcount!=posi-1){
        temp = temp->link;
        currentcount++;
    }
    new_node->link = temp->link;
    temp->link = new_node;
    
}

void updateatposi(node* head , int val, int posi){// for udtaing an node value in linked list.
    if(posi<0 || posi>ll_length(head)){ // check that posi is not out of the bound.
       cout << "position not found !" << endl;
       return;
    }

    node* temp = head;
    int ccount = 0;
    while(ccount!=posi){
        temp = temp->link;
        ccount++;
    } 

    temp->value = val;
}

void print(node * head){// func for display linked list.
    node* temp = head;
    while(temp!=NULL){
        cout << temp->value << " --- ";
        temp = temp->link;
    }

    cout << "NULL" << endl;
}

void dlt_head(node*& head) { // node detilion from strating.
    if (head != nullptr) {
        node* temp = head;
        head = head->link;
        delete temp;
    }
}

void delete_list(node*& head) { // delete whole list.
    while (head != nullptr) {
        dlt_head(head);
    }
}

int main(){
    node* head = NULL;
    insert(head,4);
    insert(head,5);
    insert(head,6);
    cout << "initial linked_list :- ";
    print(head);
    insertatposi(head,8,2);
    cout << "updated linked list :- ";
    print(head);

    updateatposi(head,7,3);
    cout << "updated linked list :- ";
    print(head);

    dlt_head(head);
    cout << "first node deleted :- ";
    print(head);

    dlt_head(head);
    cout << "first node deleted :- ";
    print(head);

    delete_list(head);
    cout << "whole list deleted :- ";
    print(head);
    
    return 0;
}