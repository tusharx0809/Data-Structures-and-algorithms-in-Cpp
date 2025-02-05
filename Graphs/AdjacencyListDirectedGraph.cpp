//CPP program to implemetn Adjacency list for weighted graph

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int i, int j){
    adj[i].push_back(j);
}

void displayAdjList(vector<vector<int>> &adj){
    for(int i=0; i<adj.size(); i++){
        cout<<i<<": ";
        for(int j=0; j<adj[i].size(); j++){
            cout<< adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int V = 3;
    vector<vector<int>> adj(V);

    addEdge(adj, 1, 0);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    cout<<"Adjacency List: "<<endl;
    displayAdjList(adj);

    /*
        0:
        1: 0 2
        2: 0
    */

    return 0;
}