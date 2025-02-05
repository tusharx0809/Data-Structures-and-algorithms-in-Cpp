//CPP program to transpose a graph

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int src, int dest){
    adj[src].push_back(dest);
}

void displayGraph(vector<vector<int>> &adj, int v){
    for(int i=0; i<v; i++){
        cout<<i<<"--> ";
        for(int j=0; j<adj[i].size(); j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

void transposeGraph(vector<vector<int>> &adj, vector<vector<int>> &transpose, int v){
    for(int i=0; i<v; i++){
        for(int j=0; j<adj[i].size(); j++){
            addEdge(transpose, adj[i][j], i);
        }
    }
}

int main(){
    int v = 5;
    vector<vector<int>> adj(v);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 0);
    addEdge(adj, 3, 2);
    addEdge(adj, 4, 1);
    addEdge(adj, 4, 3);

    cout<<"Graph:"<<endl;
    displayGraph(adj, v);
    cout<<endl;

    /*
        Graph:
        0--> 1 4 3
        1-->
        2--> 0
        3--> 2
        4--> 1 3
    */

    vector<vector<int>> transpose(v);
    transposeGraph(adj, transpose, v);

    cout<<"Transposed Graph:"<<endl;
    displayGraph(transpose, v);
    /*
        Transposed Graph:
        0--> 2
        1--> 0 4
        2--> 3
        3--> 0 4
        4--> 0
    */
    return 0;
}