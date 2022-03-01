// person can take either 1,2 or 3 steps at one time

#include <bits/stdc++.h>
using namespace std;
int countSteps(int n)
{
    if (n < 0)
        return 0;
    if (n == 0 || n == 1)
        return 1;
    int x = countSteps(n - 1);
    int y = countSteps(n - 2);
    int z = countSteps(n - 3);
    return (x + y + z);
}
int main()
{
    int n;
    cout << "Enter no. Of Stairs: " << endl;
    cin >> n;
    int ans = countSteps(n);
    cout << "No. of ways in which he Climb the Stairs: " << ans << endl;
    return 0;
}