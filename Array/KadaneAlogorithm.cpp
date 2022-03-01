// kadane's algorithm is used to find maximum subarray Sum

#include <bits/stdc++.h>
using namespace std;
int maxSubarraySum(int *arr, int n)
{
    int sum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        if (sum > maxSum)
            maxSum = sum;
        if (sum < 0)
            sum = 0;
    }
    return maxSum;
}
int main()
{
    int n;
    cout << "Enter size of the Array:" << endl;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter Elements of Array:" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int sum = maxSubarraySum(arr, n);
    cout << "Maximum Subarray Sum: " << sum << endl;
    return 0;
}