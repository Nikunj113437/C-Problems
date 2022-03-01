// PQR is said to be 3 cycle only when there is edge between P and Q , Q and R,
// P and R 


#include <bits/stdc++.h>
using namespace std;
void threeCycle(int **edges, int n, int &count)
{
    if (n == 0)
        return;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            if(edges[i][j]==1){
                for (int k = 0; k < n;k++){
                    if(edges[j][k]==1){
                        if(edges[i][k]==1)
                            count++;
                    }
                }
            }
        }
    }
    count = count / 6;
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
    int count = 0;
    
    threeCycle(edges, n, count);
    cout << "Total 3-cycles formed: " << count << endl;
    return 0;
}