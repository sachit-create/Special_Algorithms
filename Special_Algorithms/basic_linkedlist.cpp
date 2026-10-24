#include <iostream>
using namespace std;

class node {
public:
    int value;
    node* link;

    node(int val) : value(val), link(nullptr) {}
};

int ll_length(node* head) {
    node* temp = head;
    int lcount = 0;
    while (temp != nullptr) {
        lcount++;
        temp = temp->link;
    }
    return lcount;
}

void insert(node*& head, int v) {
    node* new_node = new node(v);
    new_node->link = head;
    head = new_node;
}

void insertatposi(node*& head, int val, int posi) {
    if (posi < 0 || posi > ll_length(head)) {
        cout << "position not found !" << endl;
        return;
    }

    if (posi == 0) {
        insert(head, val);
        return;
    }

    node* new_node = new node(val);
    node* temp = head;
    for (int currentcount = 0; currentcount < posi - 1; ++currentcount) {
        temp = temp->link;
    }

    new_node->link = temp->link;
    temp->link = new_node;
}

void updateatposi(node* head, int val, int posi) {
    if (head == nullptr || posi < 0 || posi >= ll_length(head)) {
        cout << "position not found !" << endl;
        return;
    }

    node* temp = head;
    for (int ccount = 0; ccount < posi; ++ccount) {
        temp = temp->link;
    }

    temp->value = val;
}

void print(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->value << " --- ";
        temp = temp->link;
    }
    cout << "NULL" << endl;
}

void dlt_head(node*& head) {
    if (head != nullptr) {
        node* temp = head;
        head = head->link;
        delete temp;
    }
}

void delete_list(node*& head) {
    while (head != nullptr) {
        dlt_head(head);
    }
}

int main() {
    node* head = nullptr;
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    cout << "initial linked_list :- ";
    print(head);

    insertatposi(head, 8, 2);
    cout << "updated linked list :- ";
    print(head);

    updateatposi(head, 7, 3);
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
