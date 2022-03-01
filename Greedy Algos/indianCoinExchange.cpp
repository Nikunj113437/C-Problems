//binarySearch function basically search for an amount present in given arry
//which is smaller and maximum than amount entered by user 



#include <bits/stdc++.h>
using namespace std;
int binarySearch(int *arr, int n, int amt)
{
    int ans;
    int si = 0;
    int ei = n - 1;
    while (si <= ei)
    {
        int mid = (si + ei) / 2;
        if (arr[mid] == amt)
            return arr[mid];
        if (arr[mid] < amt)
        {
            ans = arr[mid];
            si = mid + 1;
        }
        else
        {
            ei = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int amt;
    int count = 0;
    cout << "Enter amount that want to Exchange:" << endl;
    cin >> amt;
    int arr[] = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    int n = sizeof(arr) / __SIZEOF_INT__;
    while (amt != 0)
    {
        int ans = binarySearch(arr, n, amt);
        amt = amt - ans;
        count++;
    }
    cout << "Minimum no. Of Exchanges: " << count << endl;
    return 0;
}