//find frequency in Sorted array in which elements are repeating using binary Search

#include <bits/stdc++.h>
using namespace std;
int lowerBound(int *arr, int si, int ei, int key)
{
    int ans;
    while (si <= ei)
    {
        int mid = (si + ei) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            ei = mid - 1;
        }
        else if (key < arr[mid])
            ei = mid - 1;
        else
            si = mid + 1;
    }
    return ans;
}
int upperBound(int *arr, int si, int ei, int key)
{
    int ans;
    while (si <= ei)
    {
        int mid = (si + ei) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            si = mid + 1;
        }
        else if (key < arr[mid])
            ei = mid - 1;
        else
            si = mid + 1;
    }
    return ans;
}
int main()
{
    int n, key;
    cout << "Enter size of array:" << endl;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter elements of array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter key element:" << endl;
    cin >> key;
    int si = lowerBound(arr, 0, n - 1, key); // si of key element
    int ei = upperBound(arr, 0, n - 1, key); // ei of key element
    cout << "Frequency of " << key << " is: " << ei - si + 1 << endl;
    return 0;
}