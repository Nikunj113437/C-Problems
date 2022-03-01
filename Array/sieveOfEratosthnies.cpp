// Algo Sieve of Eratosthnies is used to find prime numbers in range from 2 to n
// n being input which user gave at runtime

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the limit at which ypu want to print prime no:" << endl;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == 0)
        {
            cout << i << " ";
            for (int j = pow(i, 2); j <= n; j += i)
            {
                arr[j] = -1;
            }
        }
    }
    return 0;
}