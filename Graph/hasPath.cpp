#include<bits/stdc++.h>
using namespace std;
bool hasPath(int**edges,int n,int sv,int ev,bool* visited){
    if(sv==ev)
        return true;
    if(edges[sv][ev]==1)
        return true;
    bool ans = false;
    visited[sv] = true;
    for (int i = 0; i < n;i++){
        if(i==sv)
            continue;
            if(edges[sv][i]==1 && !visited[i]){
                ans = hasPath(edges, n, i, ev, visited);
                if(ans)
                    return true;
            }
    }
    return ans;
}
int main(){
    int n, e,sv,ev;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n;i++){
        edges[i] = new int[n];
        for (int j = 0; j < n;j++){
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e;i++){
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n;i++){
        visited[i] = false;
    }
    cin >> sv >> ev;
    bool ans = hasPath(edges, n, sv, ev, visited);
    if(ans)
        cout << "True" << endl;
        else
            cout << "False" << endl;
}