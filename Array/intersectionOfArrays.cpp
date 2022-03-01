#include <bits/stdc++.h>
using namespace std;
int binarySearch(int *arr, int si, int ei, int key)
{
    while (si <= ei)
    {
        int mid = (si + ei) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            ei = mid - 1;
        else
            si = mid + 1;
    }
    return -1;
}
int main()
{
    int n, m;
    cout << "Enter size of 1st array:" << endl;
    cin >> n;
    cout << "Enter size of 2nd array:" << endl;
    cin >> m;
    int *arr1 = new int[n];
    int *arr2 = new int[m];
    cout << "Enter elements of 1st array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    cout << "Enter elements of 2nd array:" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
    if (m < n)
    {
        int c = 0;
        for (int i = 0; i < m; i++)
        {
            int ans = binarySearch(arr1, 0, n - 1, arr2[i]);
            if (ans != -1)
                c++;
        }
        cout << "Intersection of two array: " << c << endl;
    }
    else
    {
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            int ans = binarySearch(arr2, 0, m - 1, arr1[i]);
            if (ans != -1)
                c++;
        }
        cout << "Intersection of two array: " << c << endl;
    }
    return 0;
}