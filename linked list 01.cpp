#include<iostream>
using namespace std;

class Node{
    public:
    Node *next;
    int data;


    Node(){
        next = NULL;
        data = 0;
    }

    Node(int data){
        this->next = NULL;
        this->data = data;
    }

};

void InsertAtTail(Node *head, int data){
    Node *temp = head;
    while(temp->next != NULL ){
        temp = temp->next;
    }

    Node *nodeToInsert = new Node(data);
    temp->next = nodeToInsert;
}

void SearchInList(Node *head, int data){
    Node *temp = head;
    while(temp!=NULL){
        if(temp->data == data){
            cout<<"\n\nElement Found: "<<temp->data<<endl;
            return;
        }
        temp = temp->next;
    }
    cout << "\n\nElement Not Found: " << data << endl;
}

void PrintLinkedList(Node *head){
    Node *temp = head;
    while(temp->next !=NULL){
        cout<<"Data : "<<temp->data<<" Next : "<<temp->next<<endl;
        temp = temp->next;
    }

}


int main(){
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    PrintLinkedList(node1);
    cout<<"\n\n";

    cout<<"Enter an Element to Find in Single Linked List:"<<endl;
    int input;
    cin>>input;

    SearchInList(node1 , input);

    delete node1;
    delete node2;
    delete node3;
    delete node4;
    
    return 0;
}