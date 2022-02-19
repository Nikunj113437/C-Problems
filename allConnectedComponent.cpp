#include <bits/stdc++.h>
using namespace std;
void allConnectedComponent(int **edges, int n, int sv, bool *visited, vector<int> &ans)
{
    ans.push_back(sv);
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
            continue;
        if (edges[sv][i] == 1 && !visited[i])
        {
            allConnectedComponent(edges, n, i, visited, ans);
        }
    }
}
int main()
{
    int n, e;
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
    for (int i = 0; i < n; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        temp.clear();
        if (!visited[i])
        {
            allConnectedComponent(edges, n, i, visited, temp);
            sort(temp.begin(), temp.end());
            for (int i = 0; i < temp.size(); i++)
            {
                cout << temp[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}