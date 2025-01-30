//CPP Program to construct a binary tree from given InOrder and LevelOrder Traversal

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

int searchValue(vector<int> inorder, int value, int s, int e){
    for(int i=s;i<=e;i++){
        if(inorder[i] == value){
            return i;
        }
    }
    return -1;
}

Node *buildTreeRecur(vector<int> &inorder, vector<int> &level, int s, int e){
    if(s > e){
        return nullptr;
    }

    Node *root = new Node(level[0]);

    int index = searchValue(inorder, level[0], s , e);

    int lcnt = index-s, rCnt = e-index;

    vector<int> lLevel(lcnt);
    vector<int> rLevel(rCnt);

    int l = 0, r= 0;

    for(int i = 1;i<e-s+1;i++){
        int j = searchValue(inorder, level[i], s, e);
        if(j < index){
            lLevel[l++] = level[i];
        }else{
            rLevel[r++] = level[i];
        }
    }
    root->left = buildTreeRecur(inorder, lLevel, s, index -1);
    root->right = buildTreeRecur(inorder, rLevel, index+1, e);

    return root;
}

Node *buildTree(vector<int> &inorder, vector<int> &level, int n){
    Node *root = buildTreeRecur(inorder, level, 0, n-1);
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
    vector<int> in = {4, 8, 10, 12, 14, 20, 22};
    vector<int> level = {20, 8, 22, 4, 12, 10, 14};
    int n = level.size();
    Node *root = buildTree(in, level, n);

    inOrder(root);

    return 0;
}