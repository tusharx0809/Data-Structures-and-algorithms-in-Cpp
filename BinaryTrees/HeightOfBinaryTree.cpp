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

//Recursive approach //O(n) Time and O(h) Space
int heightUsingRecursion(Node *root){
    if(root == nullptr) return -1;

    int left_height = heightUsingRecursion(root->left);
    int right_height = heightUsingRecursion(root->right);

    return max(left_height, right_height) + 1;
}

//Level Order traversal approcah // O(n) Time and O(h) Space
int heightUsingLevelOrderTraversal(Node *root){
    if(!root) return 0;

    int height = 0;
    
    queue<Node *> q;

    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node *cur = q.front();
        q.pop();

        if(cur == nullptr){
            height++;

            if(!q.empty()){
                q.push(nullptr);
            }
        }else{
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
    }
    return height - 1;
    
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
    cout<<endl;
    cout<< heightUsingLevelOrderTraversal(root);

    return 0;
}