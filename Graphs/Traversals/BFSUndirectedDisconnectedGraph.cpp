//CPP program for disconnected undirected graph

//CPP program for BFS of an undirecred graph

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(vector<vector<int>> &adj, int s, vector<bool> &visited){
    queue<int> q; //Create a queue for BFS

    visited[s] = true; //mark first vertex as visited

    q.push(s);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout<< curr <<" ";

        for(int x: adj[curr]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

void bfsDisconnected(vector<vector<int>> &adj){
    vector<bool> visited(adj.size(), false);

    for(int i=0; i<adj.size(); i++){
        if(!visited[i]){
            bfs(adj, i, visited);
        }
    }
}


int main(){
    int V = 6;

    vector<vector<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);

    /*
        0: 1, 2
        1: 0
        2: 0
        3: 4
        4: 3 5
        5: 4                   

    */

    bfsDisconnected(adj); //0 1 2 3 4 5

    return 0;
}