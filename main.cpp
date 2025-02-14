#include<iostream>
using namespace std;

class Node{
    public :

    Node* next; // the adderss of the next node
    int data; // node data 

    Node(){
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

};

int main(){
    
    cout<<"\n\nHello Creating a Single Linked List \n\n"<<endl;
    Node* node0 = new Node(1);
    Node* node1 = new Node(2);
    Node* node2 = new Node(3);

    node0->next = node1;
    node1->next = node2;

    Node* temp = node0;
    while(temp != NULL){ //loop till we reach the end node
        cout<<"Node Data: "<<temp->data<<" | Next Node: "<<temp->next<<endl;

        temp = temp->next;
    }

    

    delete node0;
    delete node1;
    delete node2;

    return 0;
}