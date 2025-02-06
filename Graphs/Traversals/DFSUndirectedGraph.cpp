//CPP program for DFS in Undirected Graph

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSRec(vector<vector<int>> &adj, vector<bool> &visited, int s){
    visited[s] = true;

    cout<<s<<" ";

    for(int i: adj[s]){
        if(visited[i] == false){
            DFSRec(adj, visited, i);
        }
    }
}

void DFS(vector<vector<int>> &adj, int s){
    vector<bool> visited(adj.size(), false);
    DFSRec(adj, visited, s);
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
    int V = 5;
    vector<vector<int>> adj(V);

    vector<vector<int>> edges = {{1,2},{1,0},{2,0},{2,3},{2,4}};

    for(auto &e: edges){
        addEdge(adj, e[0], e[1]);
    }

    printGraph(adj);
    cout<<endl;
    /*
        0: 1 2 
        1: 2 0
        2: 1 0 3 4
        3: 2
        4: 2
    */

    int s = 1;
    cout<<"DFS from source: "<<s<< endl;
    DFS(adj, s);
    /*
        DFS from source: 1
        1 2 0 3 4
    */
   
    return 0;
}