//CPP program to implement undirected and unweighted graph using Adjacency List

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int i, int j){
    adj[i].push_back(j);
    adj[j].push_back(i);
}

void displayAdjList(const vector<vector<int>> &adj){
    for(int i=0; i<adj.size(); i++){
        cout<<i<<": ";
        for(int j: adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main(){
    //Create graph with 4 vertices and no edges

    int V = 4;
    vector<vector<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    cout<<"Adjacency List: "<<endl;
    displayAdjList(adj);

    /*
        0: 1 2
        1: 0 2
        2: 0 1 3
        3: 2
    */

    return 0;
}