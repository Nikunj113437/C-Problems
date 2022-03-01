#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter size of array:" << endl;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter elements of array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            if (i != j)
            {
                swap(arr[i], arr[j]); // using inbuilt swap function
                j++;
            }
        }
    }
    cout << "After placing all negative element at one side:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}