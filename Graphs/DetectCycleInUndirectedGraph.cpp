//CPP program to detect cycle in undirected graph

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<vector<int>> &adj){
    for(int i=0; i<adj.size(); i++){
        cout<<i<<": ";
        for(int j=0; j<adj[i].size(); j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int vertices = 3;
    vector<vector<int>> adj(vertices);

    vector<pair<int,int>> edges = {{0,1}, {0,2}, {1,2}};

    for(auto& edge: edges){
        addEdge(adj, edge.first, edge.second);
    }

    printGraph(adj);

    /*
        0: 1 2 
        1: 0 2
        2: 0 1
    */
    return 0;
}