#include <bits/stdc++.h>
using namespace std;
int minimumJumps(int *arr, int si, int ei)
{
    int c = 0;
    for (int i = si; i <= ei;)
    {
        int k = i + arr[i];
        if (k >= ei - i)
            return c + 1;
        else
            c++;
        i = i + arr[i];
    }
    return -1;
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
    int ans = minimumJumps(arr, 0, n - 1);
    if (ans == -1)
        cout << "No minimum Jumps found to reach to end" << endl;
    else
        cout << "Minimum Jumps to reach to end: " << ans << endl;
    return 0;
}