//CPP program to implement Binary Search Tree

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

Node *insert(Node *root, int key){
    if(root == nullptr) return new Node(key);

    if(root->data == key) return root;

    if(root->data < key){
        root->right = insert(root->right, key);
    }else{
        root->left = insert(root->left, key);
    }
    return root;
}
void inOrder(Node *root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
int main(){
    // Creating the following BST
    //      50
    //     /  \
    //    30   70
    //   / \   / \
    //  20 40 60 80

    Node* root = new Node(50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    
    inOrder(root);

    return 0;
}