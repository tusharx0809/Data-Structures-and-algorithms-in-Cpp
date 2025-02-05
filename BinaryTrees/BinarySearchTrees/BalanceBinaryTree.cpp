//CPP program to balance an unbalanced binary tree

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int x){
            data = x;
            left = right = nullptr;
        }
};

void inOrder(Node *root){
    if(root == nullptr) return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main(){
    //Constructing an unbalanced BST
    //          10
    //         /  \
    //        5   15
    //       /      \
    //      2        20
    //     /
    //    1

    Node *root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->right = new Node(15);
    root->right->right = new Node(20);

    inOrder(root); //1 2 5 10 15 20

    return 0;
}