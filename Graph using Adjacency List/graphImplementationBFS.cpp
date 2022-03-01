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
    void BFSHelper(int sv, unordered_map<int, int> &visited)
    {
        visited[sv] = 1;
        queue<int> helper;
        helper.push(sv);
        while (!helper.empty())
        {
            int front = helper.front();
            helper.pop();
            cout << front << " ";
            for (auto x : l[front])
            {
                if (!visited[x])
                {
                    helper.push(x);
                    visited[x] = 1;
                }
            }
        }
    }
    void BFS(int sv)
    {
        unordered_map<int, int> visited;
        for (int i = sv; i < n; i++)
        {
            if (!visited[i])
            {
                BFSHelper(i, visited);
            }
        }
        for (int i = 0; i < sv; i++)
        {
            if (!visited[i])
            {
                BFSHelper(i, visited);
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
    g.BFS(7);
    return 0;
}