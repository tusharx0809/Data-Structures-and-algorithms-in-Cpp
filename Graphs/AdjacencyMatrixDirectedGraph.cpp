//CPP program to implement adjacency matrix for directed graph

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &mat, int i, int j){
    mat[i][j] = 1;
}

void displayAdjMatrix(vector<vector<int>> &mat){
    for(int i=0; i<mat.size(); i++){
        for(int j=0;j<mat.size(); j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int V = 3;
    
    vector<vector<int>> mat(V, vector<int>(V, 0));

    addEdge(mat, 1, 0);
    addEdge(mat, 1, 2);
    addEdge(mat, 2, 0);

    cout<<"Adjacency Matrix:"<<endl;
    displayAdjMatrix(mat);

    /*
        0 0 0
        1 0 1
        1 0 0
    */
   
    return 0;
}