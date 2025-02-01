//CPP program to delete a node from BST

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

Node *insert(Node *root, int key){
    Node *newNode = new Node(key);
    if(root == nullptr) return newNode;
    
    Node *parent = nullptr, *cur = root;

    while(cur != nullptr){
        parent = cur;
        if(cur->data > key){
            cur = cur->left;
        }else if(cur->data < key){
            cur = cur->right;
        }else{
            return root;
        }
    }

    if(parent->data > key){
        parent->left = newNode;
    }else{
        parent->right = newNode;
    }
    return root;
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
     /*
                      50
                   /      \
                 30        70
               /    \     /    \
             20      40  60     80
            /  \    /  \  / \   /  \
          10   25 35  45 55 65 75  85
*/

    Node* root = new Node(50);
    vector<int> nodes = {30, 20, 40, 70, 60, 80, 10, 25, 35, 45, 55, 65, 75, 85};
    
    for(int val: nodes){
        root = insert(root, val);
    }
    
    inOrder(root); //20 30 40 50 60 70 80
    cout<<endl;
    return 0;
}