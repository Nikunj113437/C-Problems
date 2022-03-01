#include <bits/stdc++.h>
using namespace std;
int minimiseMaxDifference(int *arr, int si, int ei, int n, int k)
{
    int temp1[n], temp2[n]; // temp1 reperesent height after adding K
    for (int i = si; i <= ei; i++)
    { // temp2 reperesent height after decrement by k
        temp1[i] = arr[i] + k;
        if (arr[i] - k < 0)
        {
            temp2[i] = arr[i] + k;
        }
        else
            temp2[i] = arr[i] - k;
    }
    int x = temp1[ei] - temp1[si];
    int y = temp2[ei] - temp2[si];
    return min(x, y);
}
int main()
{
    int n, k;
    cout << "Enter size of Array:" << endl;
    cin >> n;
    int *arr = new int[n]; // arr denotes height of n tower
    cout << "Enter Elements of Array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter Value of K:" << endl;
    cin >> k;
    sort(arr, arr + n);
    int ans = minimiseMaxDifference(arr, 0, n - 1, n, k);
    cout << "Shortest Difference between largest and smallest height: " << ans << endl;
    return 0;
}