//CPP program to balance an unbalanced binary tree

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left, *right,

        Node(int x){
            data = x;
            left = right = nullptr;
        }
}

int main(){
    //Construct an unbalanced BST

    Node *root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->right = new Node(15);
    root->right = new Node(20);
}