//CPP program for BFS of an undirecred graph

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void bfs(vector<vector<int>> &adj, int s){
    queue<int> q; //Create a queue for BFS

    vector<bool> visited(adj.size(), false); //Mark all vertices as not visited(false) initially

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

        0--------1-------3
        |         \        
        |          \    
        |           \    
        2------------4                    

    */

    bfs(adj, 0); //0 1 2 3 4

    return 0;
}