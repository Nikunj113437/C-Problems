#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter no. of White and Black balls:" << endl;
    cin >> n;
    int *wArray = new int[n];
    int *bArray = new int[n];
    cout << "Enter position of white balls:" << endl;
    for (int i = 0; i < n; i++)
        cin >> wArray[i];

    cout << "Enter position of black balls:" << endl;
    for (int i = 0; i < n; i++)
        cin >> bArray[i];

    sort(wArray, wArray + n);
    sort(bArray, bArray + n);
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        len = len + abs(wArray[i] - bArray[i]);
    }
    cout << "Minimum Length of Rope required: " << len << endl;
    return 0;
}