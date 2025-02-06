//CPP program for DFS disconnected undirecred graph

#include<bits/stdc++.h>
using namespace std;
void DFSRec(vector<vector<int>> &adj, vector<bool> &visited, int s){
    visited[s] = true;
    cout<<s<<" ";

    for(int i: adj[s]){
        if(!visited[i]){
            DFSRec(adj, visited, i);
        }
    }
}

void DFS(vector<vector<int>> &adj){
    vector<bool> visited(adj.size(), false);

    for(int i=0; i<adj.size(); i++){
        if(!visited[i]){
            DFSRec(adj, visited, i);
        }
    }
}

void addEdge(vector<vector<int>> &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<vector<int>> &adj){
    for(int i=0;i<adj.size();i++){
        cout<<i<<": ";
        for(int j=0; j<adj[i].size(); j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int V = 6;

    vector<vector<int>> adj(V);

    vector<vector<int>> edges = {{1, 2}, {2, 0}, {0, 3}, {4, 5}};

    for(auto &e: edges){
        addEdge(adj, e[0], e[1]);
    }

    printGraph(adj);
    /*
        0: 2 3 
        1: 2   
        2: 1 0 
        3: 0   
        4: 5
        5: 4
    */

    DFS(adj); //0 2 1 3 4 5
    return 0;
}