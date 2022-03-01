// Concept of sliding window is used in contiguous array and substring
// It lowers down the time complexity from O(n^2) to O(n) because we traverse along
// array only once

#include <bits/stdc++.h>
using namespace std;
void sumToK(int *arr, int si, int ei, int k)
{
    int i = si, j = si;
    int sum = 0;
    while (j <= ei)
    {
        if (sum < k)
        {
            sum = sum + arr[j]; // j++ for increasing size of window
            j++;
        }
        else if (sum > k)
        {
            sum = sum - arr[i]; // i++ for decreasing size of window
            i++;
        }
        else if (sum == k)
        {
            cout << "[" << i << "," << j - 1 << "]"
                 << "  ";
            sum = sum + arr[j];
            j++;
            sum = sum - arr[i];
            i++;
        }
    }
}
int main()
{
    int n, k;
    cout << "Enter size of road:" << endl;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter size of each house(in acres):" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter land you want to buy(in acres): " << endl;
    cin >> k;
    cout << "Segments of Contiguous plots whose sum is exactly " << k << ": " << endl;
    sumToK(arr, 0, n - 1, k);
    return 0;
}