#include <iostream>

using namespace std;

class Node{
    public:
      int data;
      Node *next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class Linklist{
    public:
      Node *head;

    Linklist(){
        head = nullptr;
    }

    void insert(int data){
        Node *new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    } 

    void display(){
        Node* temp = head;
        while(temp!=nullptr){
            cout << temp->data << " --- ";
            temp = temp->next;
        }
        cout << "NULL" << endl;;
    }

    void reverse(){
        Node* prev = nullptr;
        Node*currptr = head;

        while(currptr!=nullptr){
            Node* nxtptr = currptr->next;
            currptr->next = prev;
            prev = currptr;
            currptr = nxtptr;
        }
        head = prev;
    } 
    
    
};

int ll_length(Node *head){
        Node* temp = head;
        int count = 0;
        while(temp!=nullptr){
            count+=1;
            temp=temp->next;
        }
        return count;
    }

void compare(Node *head1 , Node *head2){
    if(ll_length(head1) != ll_length(head2)){
        cout << "linklists are not equal" << endl;
        return;
    }

    Node *temp = head1;
    Node *temp1 = head2;
    bool flag = 1;
    while(temp!=nullptr && temp1!=nullptr){
        if(temp->data != temp1->data){
            flag = 0;
            break;
        }
        temp = temp->next;
        temp1 = temp1->next;
    }
    if(flag){ 
    cout << "both linklist are same" << endl;
    }
    else{
     cout << "linklists are not same" << endl;
    }
}

int main(){
    Linklist ll1,ll2;
    ll1.insert(1);
    ll1.insert(2);
    ll1.insert(3);
    ll1.insert(4);
    ll1.insert(5);
    ll1.display();
    ll2.insert(1);
    ll2.insert(2);
    ll2.insert(3);
    ll2.insert(4);
    ll2.insert(5);
    ll2.display();
    compare(ll1.head,ll2.head);
    return 0;
}