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

void storeInorder(Node *root, vector<int> &nodes){
    if(root == nullptr) return;

    storeInorder(root->left, nodes);
    nodes.push_back(root->data);
    storeInorder(root->right, nodes);
}

Node *buildBalancedTree(vector<int> &nodes, int start, int end){
    if(start > end) return nullptr;

    int mid = (start + end) / 2;

    Node *root = new Node(nodes[mid]);
    root->left = buildBalancedTree(nodes, start, mid-1);
    root->right = buildBalancedTree(nodes, mid+1, end);

    return root;
}

Node *balanceBST(Node *root){
    vector<int> nodes;

    storeInorder(root, nodes);

    return buildBalancedTree(nodes, 0, nodes.size()-1);
}

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
    cout<<endl;

    Node *balancedRoot = balanceBST(root);
    inOrder(balancedRoot); //1 2 5 10 15 20
    
    //Constructing balanced BST
    //          10
    //         /  \
    //        2   15
    //      /  \   \
    //     1    5    20

    return 0;
}