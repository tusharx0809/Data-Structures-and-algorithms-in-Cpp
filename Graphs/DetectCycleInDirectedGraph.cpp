// CPP program to detect cycle in a directed graph

#include <bits/stdc++.h>
using namespace std;

bool isCyclicUtil(vector<vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &recStack)
{
    if (!visited[u])
    {
        visited[u] = true;
        recStack[u] = true;

        for (int x : adj[u])
        {
            if (!visited[x] && isCyclicUtil(adj, x, visited, recStack))
            {
                return true;
            }
            else if (recStack[x])
            {
                return true;
            }
        }
    }

    recStack[u] = false;
    return false;
}

bool isCyclic(vector<vector<int>> &adj, int vertices)
{
    vector<bool> visited(vertices, false);
    vector<bool> recStack(vertices, false);

    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i] && isCyclicUtil(adj, i, visited, recStack))
            return true;
    }
    return false;
}

void addDirectedEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
}

void printGraph(vector<vector<int>> &adj)
{
    for (int i = 0; i < adj.size(); i++)
    {
        cout << i << ": ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int vertices = 5; // 0, 1, 2, 3, 4
    vector<vector<int>> adj(vertices);

    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 3}, {3, 3}};

    for (auto &edge : edges)
    {
        addDirectedEdge(adj, edge.first, edge.second);
    }

    printGraph(adj);
    /*
        0: 1 2
        1: 2
        2: 0 3
        3: 3
        4:
    */

    if (isCyclic(adj, vertices))
    {
        cout << "Contains Cycle" << endl;
    }
    else
    {
        cout << "No Cycle" << endl;
    }

    return 0;
}