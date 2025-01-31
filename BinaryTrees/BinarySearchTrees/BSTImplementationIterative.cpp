//CPP program to implement BST iteratively with search operation

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

Node* insert(Node *root, int key){
    Node *temp = new Node(key);

    if(root == nullptr) return temp;

    Node *parent = nullptr, *curr = root;

    while(curr != nullptr){
        parent = curr;
        if(curr->data > key){
            curr = curr->left;
        }else if(curr->data < key){
            curr = curr->right;
        }else{
            return root;
        }
    }

    if(parent->data > key){
        parent->left = temp;
    }else{
        parent->right = temp;
    }
    return root;
}

Node *search(Node *root, int key){
    if(root == nullptr || root->data == key) return root;

    if(root->data < key) return search(root->right, key);

    return search(root->left, key);
}

void inOrder(Node *root){
    if(root == nullptr){
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
    
    inOrder(root); //20 30 40 50 60 70 80
    cout<<endl;
    (search(root, 19) != NULL) ? cout<<"Found"<<endl : cout<<"Not Found"<<endl; //Not Found
    (search(root, 20) != NULL) ? cout<<"Found"<<endl : cout<<"Not Found"<<endl; //Found

    return 0;
}