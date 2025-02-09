//CPP program to check if a tree is BST or NOT

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
        Node(int x){
            data = x;
            left = right = nullptr;
        }  
};

Node *insert(Node *root, int val){
    Node *newNode = new Node(val);

    if(root == nullptr) return newNode;

    Node *parent=nullptr, *cur = root;

    while(cur != nullptr){
        parent = cur;
        if(cur->data > val){
            cur = cur->left;
        }else if(cur->data < val){
            cur = cur->right;
        }else{
            return root;
        }
    }
    if(parent->data > val){
        parent->left = newNode;
    }else{
        parent->right = newNode;
    }
    return root;
}
bool isValidBstHelper(Node *root, long min, long max){
    if(root == nullptr) return true;

    if(root->data <= min || root->data >= max) return false;

    return isValidBstHelper(root->left, min, root->data) && isValidBstHelper(root->right, root->data, max);
}
bool isValidBst(Node *root){
    return isValidBstHelper(root, LONG_MIN, LONG_MAX);
}
void printInOrder(Node *root){
    if(root == nullptr){
        return;
    }
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}
int main(){
    Node *root = new Node(50);
    vector<int> nodes = {30, 20, 40, 70, 60, 80};

    for(int val: nodes){
        insert(root, val);
    }

    //      50
    //     /  \
    //    30   70
    //   / \   / \
    //  20 40 60 80

    printInOrder(root); //20 30 40 50 60 70 80 
    cout<<endl;

    isValidBst(root) ? cout<<"Is BST\n" : cout<<"Is Not BST\n"; //Is BST

    Node *root2 = new Node(50);

    root2->left = new Node(30);
    root2->right = new Node(70);
    root2->left->left = new Node(40);
    root2->left->right = new Node(20);
    root2->right->right = new Node(80);
    root2->right->left = new Node(60);

    printInOrder(root2); //40 30 20 50 60 70 80
    cout<<endl;

    //      50
    //     /  \
    //    30   70
    //   / \   / \
    //  40 20 60 80

    isValidBst(root2) ? cout<<"Is BST\n" : cout<<"Is Not BST\n"; //Is Not BST

    return 0;
}