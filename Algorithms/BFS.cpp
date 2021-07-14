// Breadth first search: Idea taken by W3Schools

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
    vector<int> *adj;
    graph(int V)
    {
        this->V = V;
        adj = new vector<int>[V];
    }
    
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }
    
    void BFS(int s)
    {
        bool *visited = new bool[V];
        memset(visited, 0, sizeof(visited));
        
        queue<int> q;
        
        visited[s] = 1;
        q.push(s);
        
        vector<int>::iterator it;
        
        while(!q.empty())
        {
            s = q.front();
            cout << s << " ";
            q.pop();
            
            for(it = adj[s].begin(); it != adj[s].end(); it++)
            {
                if (!visited[*it])
                {
                    visited[*it] = true;
                    q.push(*it);
                }
            }
        }
    }
};

int main()
{
    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    g.BFS(2);
    return 0;
}


