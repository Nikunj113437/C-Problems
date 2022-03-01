// we have to find pair in array which sum to K
// we can done it by using two approaches
// 1st approach--->only applicable on Sorted arrays-->which is two pointer approach
// i=si  and j=ei-->currSum=arr[i]+arr[j]
// if currSum<k---> i++     if currSum>k--> j--
// if currSum==k---> print arr[i] and arr[j]   and i++  and j--
// 2nd approach is discuss in this quest and it is applicable for both sorted and
// and unsorted array ....and we use it hashmap in order to achieve it

#include <bits/stdc++.h>
using namespace std;
void pairSumToK(int *arr, int n, int k)
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        if (map.count(k - arr[i]) > 0)
        {
            cout << "(" << arr[i] << "," << k - arr[i] << ")"
                 << " ";
        }
        map[arr[i]]++;
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
    cout << "Enter the Sum K:" << endl;
    cin >> k;
    cout << "All Pairs which Sum to K:" << endl;
    pairSumToK(arr, n, k);
    return 0;
}