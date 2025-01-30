//CPP program to insert in binary tree in level order

#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
        int data;
        Node *left;
        Node *right;

        Node(int val){
            data = val;
            left = right = nullptr;
        }
};

Node *InsertNode(Node *root, int data){
    if(root == nullptr){
        root = new Node(data);
        return root;
    }

    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        Node *curr = q.front();
        q.pop();

        if(curr->left != nullptr){
            q.push(curr->left);
        }else{
            curr->left = new Node(data);
            return root;
        }
        if(curr->right != nullptr){
            q.push(curr->right);
        }else{
            curr->right = new Node(data);
            return root;
        }
    }
    return root;
}

void inOrder(Node *curr){
    if(curr == nullptr){
        return;
    }
    inOrder(curr->left);
    cout<<curr->data<<" ";
    inOrder(curr->right);
}

int main(){
    //        10
    //      /    \
    //    11     12
    //  /   \   /  \
    // 13   14 N    16


    Node *root = new Node(10);
    root->left = new Node(11);
    root->right = new Node(12);
    root->left->left = new Node(13);
    root->left->right = new Node(14);
    root->right->left = nullptr; // We will insert the node here
    root->right->right = new Node(16);
    inOrder(root); //13 11 14 10 12 16 
    cout<<endl;

    root = InsertNode(root, 15);
    inOrder(root); //13 11 14 10 15 12 16

    //  Tree after insertion
    //        10
    //      /    \
    //    11     12
    //  /   \   /  \
    // 13   14 15    16

    return 0;
}