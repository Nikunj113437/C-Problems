#include <bits/stdc++.h>
using namespace std;
vector<int> getPathBFS(int **edges, int n, int sv, int ev, bool *visited)
{
    vector<int> ans;
    unordered_map<int, int> map;
    if (sv == ev)
    {
        ans.push_back(ev);
        return ans;
    }
    visited[sv] = true;
    map[sv] = -1;
    int i = ev;
    queue<int> helper;
    helper.push(sv);
    bool found = false;
    while (!helper.empty())
    {
        int front = helper.front();
        helper.pop();
        for (int i = 0; i < n; i++)
        {
            if (i == front)
                continue;
            if (edges[front][i] == 1 && !visited[i])
            {
                helper.push(i);
                visited[i] = true;
                map[i] = front;
            }
            if (i == ev)
            {
                found = true;
                break;
            }
        }
        if (found == true)
            break;
    }
    ans.push_back(ev);
    while (map[i] != -1)
    {
        int x = map[i];
        ans.push_back(x);
        i = map[i];
    }
    return ans;
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
    for (int i = 0; i < e; i++)
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
    int sv, ev;
    cin >> sv >> ev;
    vector<int> ans = getPathBFS(edges, n, sv, ev, visited);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}