#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    return a.second.second < b.second.second;
}
int main()
{
    int n;
    cout << "Enter no. Of Activities:" << endl;
    cin >> n;
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cout << "Enter start time and end time of " << i + 1 << " Activity:" << endl;
        cin >> start >> end;
        v.push_back(make_pair(i + 1, make_pair(start, end)));
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < n; i++)
    {
        cout << "A" << v[i].first << " [" << v[i].second.first << "," << v[i].second.second
             << "]" << endl;
    }
    cout << "Activities considered are:" << endl;
    cout << "A" << v[0].first << " ";
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[j].second.second <= v[i].second.first)
        {
            cout << "A" << v[i].first << " ";
            j = i;
        }
    }
    return 0;
}