#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int n; // n is total no. of vertices
    list<int> *l;

public:
    Graph(int n)
    {
        this->n = n;
        l = new list<int>[n];
    }
    void addEdges(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void DFSHelper(int sv, unordered_map<int, int> &visited)
    {
        cout << sv << " ";
        visited[sv] = 1;
        for (auto x : l[sv])
        {
            if (!visited[x])
            {
                DFSHelper(x, visited);
            }
        }
    }
    void DFS(int sv)
    {
        unordered_map<int, int> visited;
        for (int i = sv; i < n; i++)
        {
            if (!visited[i])
            {
                DFSHelper(i, visited);
            }
        }
        for (int i = 0; i < sv; i++)
        {
            if (!visited[i])
            {
                DFSHelper(i, visited);
            }
        }
    }
};
int main()
{
    Graph g(9);
    g.addEdges(0, 6);
    g.addEdges(0, 5);
    g.addEdges(0, 4);
    g.addEdges(6, 2);
    g.addEdges(2, 5);
    g.addEdges(5, 4);
    g.addEdges(3, 1);
    g.addEdges(1, 7);
    g.addEdges(8, 7);
    g.addEdges(3, 8);
    g.addEdges(3, 7);
    g.DFS(7);
    return 0;
}