// in this quest we merge two sorted array in different manner...ie without uising an
// extra space..
// arr1[m+n]--> but elements are filled upto m only...rest of elements are 0
// arr2[n]--->it's size is n

#include <bits/stdc++.h>
using namespace std;
void mergeTwoSortedArray(int *arr1, int *arr2, int m, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (arr1[i] > arr2[j])
        {
            arr1[k] = arr1[i];
            i--;
            k--;
        }
        else if (arr2[j] > arr1[i])
        {
            arr1[k] = arr2[j];
            j--;
            k--;
        }
    }
    while (i >= 0)
    {
        arr1[k] = arr1[i];
        i--;
        k--;
    }
    while (j >= 0)
    {
        arr1[k] = arr2[j];
        j--;
        k--;
    }
    for (int i = 0; i < m + n; i++)
    {
        cout << arr1[i] << " ";
    }
}
int main()
{
    int m, n;
    cout << "Enter size of 1st Array:" << endl;
    cin >> m;
    cout << "Enter size of 2nd Array:" << endl;
    cin >> n;
    int *arr1 = new int[m + n];
    int *arr2 = new int[n];
    cout << "Enter Elements of 1st Array:" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }
    for (int i = m; i < m + n; i++)
    {
        arr1[i] = 0;
    }
    cout << "Enter Elements of 2nd Array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    cout << "After Sorting Final Array: " << endl;
    mergeTwoSortedArray(arr1, arr2, m, n);
    return 0;
}