#include <bits/stdc++.h>
using namespace std;
void printBFS(int **edges, int n, int sv, bool *visited)
{
    if (n == 0)
        return;
    queue<int> helper;
    helper.push(sv);
    visited[sv] = true;
    while (!helper.empty())
    {
        int front = helper.front();
        helper.pop();
        cout << front << " ";
        for (int i = 0; i < n; i++)
        {
            if (i == front)
                continue;
            if (edges[front][i] == 1 && !visited[i])
            {
                helper.push(i);
                visited[i] = true;
            }
        }
    }
}
int main()
{
    int n, e;
    cout << "Enter no. Of Vertices and Edges:" << endl;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cout << "Enter first and second vertex of an edge:" << endl;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = true;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printBFS(edges, n, i, visited);
        }
    }
    return 0;
}