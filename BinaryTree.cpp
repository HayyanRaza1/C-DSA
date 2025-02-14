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

int findMin(Node* root){
    if(root == nullptr) return INT_MAX;
    return min(root->data, min(findMin(root->left), findMin(root->right)));
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
    root->left = new Node(data);
}


void InsertNodeAtRight(Node* root, int data){
    root->right = new Node(data);
}

void DeleteNode(Node*& node){

    cout<<"\nDeleted Node: "<<node<<"  With Childs : "<<node->left->data<<","<<node->right->data<<" And Data " <<node->data<<endl;
    delete node->left;
    delete node->right;
    node->left = nullptr;
    node->right = nullptr;
    delete node;
    node = nullptr;
}

int main(){
    Node *root = new Node(0);

    Node *node1 = new Node(1);
    Node *node2 = new Node(2);

    root->left = node1;
    root->right = node2;

    system("cls");
    system("cls");
    InsertNodeAtLeft(node1 , 3);
    InsertNodeAtRight(node1 , 4);
    
    InsertNodeAtLeft(node2 , 5);
    InsertNodeAtRight(node2 , 6);
    
    cout<<"\nMax Value In The Tree is :"<<findMax(root);
    cout<<"\nMin Value In The Tree is :"<<findMin(root);

    DeleteNode(node2);

    int dataToFind;

    cout<<"\n";
    cin>>dataToFind;
    
    if(searchInTree(root , dataToFind)){
        //Data Found
    }else{
        cout<<"No Data Found :("<<endl;
    }

    return 0;
}