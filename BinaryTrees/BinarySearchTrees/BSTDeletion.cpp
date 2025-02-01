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

Node *getSuccessor(Node *cur){
    cur = cur->right;
    while(cur != nullptr && cur->left != nullptr){
        cur = cur->left;
    }
    return cur;
}

Node *delNode(Node *root, int x){
    if(root == nullptr) return root; 

    if(root->data > x){
        root->left = delNode(root->left, x);
    }else if(root->data < x){
        root->right = delNode(root->right, x);
    }else{
        if(root->left == nullptr){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if(root->right == nullptr){
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *succ = getSuccessor(root);
        root->data = succ->data;
        root->right = delNode(root->right, succ->data);
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
    inOrder(root); //10 20 25 30 35 40 45 50 55 60 65 70 75 80 85 
    cout<<endl;


    delNode(root, 25); //Deleting Leaf Node 25
    inOrder(root); //10 20 30 35 40 45 50 55 60 65 70 75 80 85
    cout<<endl;
     /*
                      50
                   /      \
                 30        70
               /    \     /    \
             20      40  60     80
            /       /  \  / \   /  \
           10     35  45 55 65 75  85
*/

    

    delNode(root, 20); //deleting node with one child
    inOrder(root);  //10 30 35 40 45 50 55 60 65 70 75 80 85
    cout<<endl;

/*
                      50
                   /      \
                 30        70
               /    \     /    \
             10      40  60     80
                    /  \  / \   /  \
                   35  45 55 65 75  85
*/

    delNode(root, 30);
    inOrder(root); //25 35 40 45 50 55 60 65 70 75 80 85
    cout<<endl;
/*
                      50
                   /      \
                 35        70
               /    \     /    \
             10      40  60     80
                       \  / \   /  \
                       45 55 65 75  85

*/
    return 0;
}