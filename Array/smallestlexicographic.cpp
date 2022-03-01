#include <bits/stdc++.h>
using namespace std;
bool compare(string s1, string s2)
{
    return (s1 + s2) < (s2 + s1);
}
int main()
{
    int n;
    cout << "Enter no. of Strings: " << endl;
    cin >> n;
    vector<string> v;
    cout << "Enter the Strings:" << endl;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < n; i++)
    {
        cout << v[i];
    }
    return 0;
}