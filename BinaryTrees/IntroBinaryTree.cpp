//Intro to binary tree


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

int main(){

    //Initialize the nodes
    Node *firstNode = new Node(2);
    Node *secondNode = new Node(3);
    Node *thirdNode = new Node(4);
    Node *fourthNode = new Node(5);

    //Connect binary tree nodes
    firstNode->left = secondNode;
    firstNode->right = thirdNode;
    secondNode->left = fourthNode;

    return 0;
}