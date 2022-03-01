//we have to print all those to numbers which have count greater tha n/k

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    int n, k;
    cout << "Enter size of array:" << endl;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the array:" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter value of k:" << endl;
    cin >> k;
    int x = n / k;
    sort(arr, arr + n);
    int c = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[i + 1])
            c++;
        else
        {
            if (c > x)
                v.push_back(arr[i]);
            else
                c = 1;
        }
    }
    cout << "Required Elements:" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}