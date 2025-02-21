//Given a weighted graph and a source vertex in the graph, find the shortest paths from the source to all the other vertices in the given graph.

#include<bits/stdc++.h>
using namespace std;

#define V 9

int minDistance(vector<int> &dist, vector<bool> &sptSet){
    int min = INT_MAX, min_index;
    for(int v=0; v<V; v++){
        if(!sptSet[v] && dist[v] <= min){
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}

void printSolution(vector<int> &dist){
    cout<<"Vertex \t distance from source"<<endl;
    for(int i=0; i<V; i++){
        cout<<i<<"\t\t\t\t"<<dist[i]<<endl;
    }
}

void dijkstra(vector<vector<int>> &graph, int src){
    vector<int> dist(V, INT_MAX);
    vector<bool> sptSet(V, false);

    dist[src] = 0;

    for(int count=0; count<V-1; count++){
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for(int v=0; v<V; v++){
            if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            } 
        }
    }

    
    printSolution(dist);
}

int main(){

    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    dijkstra(graph, 0);

    return 0;
}