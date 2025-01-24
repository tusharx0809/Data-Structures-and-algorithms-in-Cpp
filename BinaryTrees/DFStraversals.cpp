//CPP program for DFS traversals in binary trees

//          2
//       /   \'
//      3     4
//     / \   / \'
//    5   N N   N
//   / \'
//  N   N

//Above 2 is root Node 2->left = 3, 2->right = 4, 2 is parent of 3 and 4
//                     3->left = 5, 3->right = nullptr, 3 is parent of 5
//                     4->left = nullptr, 4->right = nullptr, 5->left = nullptr and 5->right = nullptr


#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int d){
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

void preOrderDFS(Node *node){
    if(node == nullptr){
        return;
    }

    cout<<node->data<<" ";
    preOrderDFS(node->left);
    preOrderDFS(node->right);
}

int main(){

    //Initialize the nodes
    Node *root = new Node(2);
    root->left = new Node(3);
    root->right = new Node(4);
    root->left->left = new Node(5);

    //Traversals
    cout<<"PreOrder Traversal: ";
    preOrderDFS(root);

    return 0;
}