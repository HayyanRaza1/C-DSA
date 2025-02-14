#include<iostream>
using namespace std;

class Node{
    public:
    Node *prev;
    Node *next;
    int data;

    Node(int data){
        prev = next = nullptr;
        this->data = data;
    }

};

void PrintList(Node *head){
    Node* temp = head;
    do{
        cout<<"Next: "<<temp->next<<" Previous: "<<temp->prev<<" Data: "<<temp->data<<endl;
        temp = temp->next;
    }
    while(head!=temp);
}

int main(){
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;

    node1->prev = node3;
    node2->prev = node1;
    node3->prev = node2;

        cout<<"\n\n";
    PrintList(node1);

    delete node1;
    delete node2;
    delete node3;

    return 0;
}