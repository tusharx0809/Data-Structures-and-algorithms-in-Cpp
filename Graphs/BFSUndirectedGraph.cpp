//CPP program for BFS of an undirecred graph

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int V = 5;

    vector<vector<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    /*
        0: 1 2
        1: 0 3 4
        2: 0 4
        3: 1
        4: 1 2
    */
    return 0;
}