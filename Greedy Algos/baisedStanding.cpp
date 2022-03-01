// we have to count badness
// badness means diffrence between preferred position and allocated position
// we have to count total badness in this quest

#include <bits/stdc++.h>
using namespace std;
bool compare(pair<string, int> a, pair<string, int> b)
{
    return a.second < b.second;
}
int main()
{
    vector<pair<string, int>> v;
    int n;
    cout << "Enter no. Of teams:" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        int x;
        cout << "Enter name and Preferred ranking of " << i + 1 << " team:" << endl;
        cin >> s >> x;
        v.push_back(make_pair(s, x));
    }
    sort(v.begin(), v.end(), compare);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += abs((i + 1) - v[i].second);
    }
    cout << "Total Badness is: " << count << endl;
    return 0;
}