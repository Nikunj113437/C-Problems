// inversion--->  arr[i]>arr[j]...and i<j
// we count total inversions by mergeSort....as total no. of inversions are difference
// between sorted and unsorted array

#include <bits/stdc++.h>
using namespace std;
int merge(int *arr, int si, int ei)
{
    int mid = (si + ei) / 2;
    int i = si, j = mid + 1, k = 0;
    int temp[1000];
    int count = 0;
    while (i <= mid && j <= ei)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else if (arr[i] > arr[j])
        {
            temp[k] = arr[j];
            k++;
            j++;
            count += mid - i + 1;
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
        k++;
        j++;
    }
    k = 0;
    for (int i = si; i <= ei; i++)
    {
        arr[i] = temp[k];
        k++;
    }
    return count;
}
int mergeSort(int *arr, int si, int ei)
{
    if (si >= ei)
        return 0;
    int mid = (si + ei) / 2;
    int x = mergeSort(arr, si, mid);     // x gives total inversions in left
    int y = mergeSort(arr, mid + 1, ei); // y gives total inversions in right
    int z = merge(arr, si, ei);          // z gives total cross inversions
    return (x + y + z);
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
    int ans = mergeSort(arr, 0, n - 1);
    cout << "Total no. of inversions: " << ans << endl;
    return 0;
}