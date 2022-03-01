#include <bits/stdc++.h>
using namespace std;
int kthSmallest(int *arr, int n, int k)
{
    int c = 0;
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int temp[max + 1];
    for (int i = 0; i < max + 1; i++)
    {
        temp[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        temp[arr[i]]++;
    }
    int index = -1;
    for (int i = 0; i < max + 1 && c < k; i++)
    {
        if (temp[i] != 0)
        {
            c++;
            index = i;
        }
    }
    return index;
}
int main()
{
    int n, k;
    cout << "Enter elements of array:" << endl;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter elements of array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter k:" << endl;
    cin >> k;
    int ans = kthSmallest(arr, n, k);
    cout << k << "th Smallest element in array: " << ans << endl;
    return 0;
}