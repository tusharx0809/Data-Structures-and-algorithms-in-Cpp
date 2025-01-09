//This program includes operations(insertion, deletion and reverse) on a Circular linked list



    // --->  1 -> 2 -> 3 -> 4 --
    // |_______________________|



#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    Node* next = NULL;
};

class CircularLinkedList{
    Node* head;

    public:
    CircularLinkedList() : head(NULL) {};


};