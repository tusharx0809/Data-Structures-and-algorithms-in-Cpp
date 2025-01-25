//CPP to program to implement breadth first search using a stack(recursive approach)

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;

        //Constructor to initialize a new node
        Node(int value){
            data = value;
            left = nullptr;
            right = nullptr;
        }
};

//Helper function for recursive level order traversal
void levelOrderRec(Node *root, int level, vector<vector<int>>& res){

    //base case: if root is null
    if(root == nullptr) return;

    //Add a new level to the result if needed
    if(res.size() <= level){
        res.push_back({});
    }

    //add current node data to its corresponding level
    res[level].push_back(root->data);

    //recur for left and right children
    levelOrderRec(root->left, level+1, res);
    levelOrderRec(root->right, level+1, res);
}


//Function to perform level order traversal
vector<vector<int>> levelOrder(Node *root){
    //Store the result level by level
    vector<vector<int>> res;
    levelOrderRec(root, 0, res);
    return res;
}

int main(){
    // Create binary tree
      //      1         
    //     / \       
    //    3   2      
    //          \   
    //           4 
    //          /  \
    //         6    5
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->right->right = new Node(4);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(5);
    
    // Perform level order traversal
    vector<vector<int>> res = levelOrder(root);

    // Print the result
    for (vector<int> level : res) 
        for (int data : level)
            cout << data << " ";
    return 0;
}