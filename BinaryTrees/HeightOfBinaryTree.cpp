//CPP program to find height of binary tree

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int val){
            data = val;
            left = nullptr;
            right = nullptr;
        }
};

//Recursive approach
int heightUsingRecursion(Node *root){
    if(root == nullptr) return -1;

    int left_height = heightUsingRecursion(root->left);
    int right_height = heightUsingRecursion(root->right);

    return max(left_height, right_height) + 1;
}

int main(){

    // Representation of the input tree:
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << heightUsingRecursion(root); //2
    return 0;
}