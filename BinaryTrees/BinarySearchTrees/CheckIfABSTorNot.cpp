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

    printInOrder(root);
    return 0;
}