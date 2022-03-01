//modified binary search is applied those array which consist of 
//two sorted subarray

#include <bits/stdc++.h>
using namespace std;
int modifiedBinarySearch(int *arr, int si, int ei, int key)
{
    while (si <= ei)
    {
        int mid = (si + ei) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] <= arr[ei])
        {
            if (key > arr[mid] && key <= arr[ei])
                si = mid + 1;
            else
                ei = mid - 1;
        }
        else if (arr[mid] >= arr[si])
        {
            if (key >= arr[si] && key < arr[mid])
                ei = mid - 1;
            else
                si = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int n, key;
    cout << "Enter size of Array:" << endl;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter elemnts of Array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter key Element:" << endl;
    cin >> key;
    int ans = modifiedBinarySearch(arr, 0, n - 1, key);
    if (ans == -1)
    {
        cout << "Not present" << endl;
    }
    else
        cout << "Key Element present at " << ans + 1 << " position" << endl;
    return 0;
}