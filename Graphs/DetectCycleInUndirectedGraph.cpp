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
bool isCyclicUtil(int v, vector<vector<int>> &adj, vector<bool> &visited, int parent){
    visited[v] = true;

    for(int i: adj[v]){
        if(!visited[i]){
            if(isCyclicUtil(i, adj, visited, v)){
                return true;
            }
        }else if(i != parent){
            return true;
        }
    }
    return false;
}

bool isCyclic(vector<vector<int>> &adj, int vertices){
    vector<bool> visited(vertices, false);

    for(int i=0; i<vertices; i++){
        if(!visited[i]){
            if(isCyclicUtil(i, adj, visited, -1)){
                return true;
            }
        }
    }
    return false;
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

    isCyclic(adj, vertices) ? cout<<"Contains Cycle\n" : cout<< "No Cycle\n";

    return 0;
}