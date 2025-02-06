//CPP program to find shortest path from source vertex to each vertex in Binary Weight Graph

#include<bits/stdc++.h>
using namespace std;

#define V 9//( vertices)
struct Node{
    int to, weight;
};

vector<Node> edges[V]; // vector to store edges

void zeroOneBFS(int src){
    int dist[V];
    for(int i=0; i<V; i++){
        dist[i] = INT_MAX;
    }

    //Double ended queue
    deque<int> Q;
    dist[src] = 0;
    Q.push_back(src);

    while(!Q.empty()){
        int v = Q.front();
        Q.pop_front();

        for(int i=0; i<edges[v].size(); i++){
            if(dist[edges[v][i].to] > dist[v] + edges[v][i].weight){
                dist[edges[v][i].to] = dist[v] + edges[v][i].weight;
                if(edges[v][i].weight == 0){
                    Q.push_front(edges[v][i].to);
                }else{
                    Q.push_back(edges[v][i].to);
                }
            }
        }
    }

    for(int i=0; i<V; i++){
        cout<<i<<": "<<dist[i]<<endl;
    }
}

void addEdge(int u, int v, int wt){
    edges[u].push_back({v, wt});
    edges[v].push_back({u, wt});
}

int main(){

    addEdge(0, 1, 0);
    addEdge(0, 7, 1);
    addEdge(1, 7, 1);
    addEdge(1, 2, 1);
    addEdge(2, 3, 0);
    addEdge(2, 5, 0);
    addEdge(2, 8, 1);
    addEdge(3, 4, 1);
    addEdge(3, 5, 1);
    addEdge(4, 5, 1);
    addEdge(5, 6, 1);
    addEdge(6, 7, 1);
    addEdge(7, 8, 1);

    int src = 0;

    zeroOneBFS(src);
    //Shortest Distances from zero to each vertex
    /*
        0: 0
        1: 0
        2: 1
        3: 1
        4: 2
        5: 1
        6: 2
        7: 1
        8: 2
    */

    return 0;
}