// we have to find si and ei of contiguous subarray which sum to K using sliding window concept
// 0 may also present in array
#include <bits/stdc++.h>
using namespace std;
void subarraySumToK(int *arr, int si, int ei, int k)
{
    int i = si, j = si;
    int sum = 0;
    while (j <= ei)
    {
        if (sum < k)
        { // if sum<k it means we have to increase the size of window
            sum = sum + arr[j];
            j++;
        }
        else if (sum > k)
        { // if sum>k it means we have to decrease the size of window
            sum = sum - arr[i];
            i++;
        }
        else if (sum == k)
        {
            cout << "[" << i << "," << j - 1 << "]"
                 << "  ";
            if (arr[i] == 0)
            {
                if (arr[j] == 0)
                {
                    cout << "[" << i << "," << j << "]"
                         << " ";
                    cout << "[" << i + 1 << "," << j - 1 << "]"
                         << " ";
                    cout << "[" << i + 1 << "," << j << "]"
                         << " ";
                    sum = sum - arr[i];
                    i++;
                    sum = sum + arr[j];
                    j += 2;
                }
                else
                {
                    sum = sum - arr[i];
                    i++;
                }
            }
            else if (arr[i] != 0)
            {
                if (arr[j] == 0)
                {
                    sum = sum + arr[j];
                    j++;
                }
                else
                {
                    sum = sum + arr[j];
                    j++;
                    sum = sum - arr[i];
                    i++;
                }
            }
        }
    }
}
int main()
{
    int n, k;
    cout << "Enter size of Array:" << endl;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter Elements of Array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter value of K:" << endl;
    cin >> k;
    cout << "Subarray whose sum to " << k << ":" << endl;
    subarraySumToK(arr, 0, n - 1, k);
    return 0;
}
