#include <bits/stdc++.h>
using namespace std;
void merge(int *arr, int si, int ei, int mid)
{
    int i = si;
    int j = mid + 1;
    int temp[1000];
    int k = 0;
    while (i <= mid && j <= ei)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else (arr[j] < arr[i])
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= ei)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int i = 0; i < = ei; i++)
    {
        arr[i] = temp[i];
    }
}
void mergeSort(int *arr, int si, int ei)
{
}
int main()
{
    int n;
    cout << "Enter size of Array:" << endl;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter Elements of Array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    return 0;
}