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


int main(){
    Node *root = new Node(0);

    Node *node1 = new Node(1);
    Node *node2 = new Node(2);

    root->left = node1;
    root->right = node2;

    cout<<"Max Value In The Tree is :"<<findMax(root);


    return 0;
}