// Depth first search

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <set>


using namespace std;

struct graph
{
    int V;
    map<int, vector<int>> adj;
    map<int, bool> visited;
    
    graph(int V)
    {
        this->V = V;
    }
    
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }
    
    
    
    void DFS(int s)
    {
        visited[s] = 1;
        cout << s << " ";
        
        for(int i = 0; i < adj[s].size(); i++)
        {
            if(!visited[adj[s][i]])
                DFS(adj[s][i]);
        }
        return;
    }
};

int main()
{
    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);
    
    g.DFS(2);
    return 0;
}
