#include <iostream>
#include <queue>

using namespace std;

class Node{
    public:

    Node *right;
    Node *left;
    int data;

    Node(int data){
        right = left = NULL;
        this->data = data;
    }
};

int findMax(Node* root) {
    if (root == nullptr) return INT_MIN;
    return max(root->data, max(findMax(root->left), findMax(root->right)));
}

bool searchInTree(Node* root , int data){
    if(root == nullptr) return false;

    if(root->data == data){
        cout<<"\nFound Data: "<< data <<" At Node:"<<root<<endl;
        return true;
    }

    return searchInTree(root->left, data) || searchInTree(root->right, data);
}

void InsertNodeAtLeft(Node* root, int data){
    Node* temp = new Node(data);
    root->left = temp;
}


void InsertNodeAtRight(Node* root, int data){
    Node* temp = new Node(data);
    root->right = temp;
}

int main(){
    Node *root = new Node(0);

    Node *node1 = new Node(1);
    Node *node2 = new Node(2);

    root->left = node1;
    root->right = node2;

    //cout<<"Max Value In The Tree is :"<<findMax(root);
    system("cls");
    system("cls");
    InsertNodeAtLeft(node1 , 3);
    InsertNodeAtRight(node1 , 4);

    InsertNodeAtLeft(node2 , 5);
    InsertNodeAtRight(node2 , 6);

    searchInTree(root , 6);

    return 0;
}