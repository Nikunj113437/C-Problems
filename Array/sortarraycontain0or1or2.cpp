#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter size of array:" << endl;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter elements of array(0,1 or 2):" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            x++;
        else if (arr[i] == 1)
            y++;
        else if (arr[i] == 2)
            z++;
    }
    int i = 0;
    while (x-- && i < n)
    {
        arr[i] = 0;
        i++;
    }
    while (y-- && i < n)
    {
        arr[i] = 1;
        i++;
    }
    while (z-- && i < n)
    {
        arr[i] = 2;
        i++;
    }
    cout << "After sorting, array become:" << endl;
    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }
    return 0;
}