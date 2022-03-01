// array will represent price of stock at that day
// we have to calculate max profit if person buys stock and sell it on day which is
// after the day of buying

#include <bits/stdc++.h>
using namespace std;
int maxProfit(int *arr, int n)
{
    int maxProfit = INT_MIN;
    int minPrice = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < minPrice)
            minPrice = arr[i];
        int profit = arr[i] - minPrice;
        if (profit > maxProfit)
            maxProfit = profit;
    }
    return maxProfit;
}
int main()
{
    int n;
    cout << "Enter no. Of Days:" << endl;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter Price of Stock:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = maxProfit(arr, n);
    cout << "Maximum Profit: " << ans << endl;
    return 0;
}