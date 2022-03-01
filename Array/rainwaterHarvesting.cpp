// if user give height 0...then in that case no buiding will be there at that point
// water is stored only when height of building at left and right is greater than
// current height of building

#include <bits/stdc++.h>
using namespace std;
int rainwaterHarvesting(int *arr, int n)
{
    int *leftMaxArray = new int[n];
    int *rightMaxArray = new int[n];
    leftMaxArray[0] = arr[0];
    rightMaxArray[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > leftMaxArray[i - 1])
        {
            leftMaxArray[i] = arr[i];
        }
        else
            leftMaxArray[i] = leftMaxArray[i - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > rightMaxArray[i + 1])
        {
            rightMaxArray[i] = arr[i];
        }
        else
        {
            rightMaxArray[i] = rightMaxArray[i + 1];
        }
    }
    int area = 0;
    for (int i = 0; i < n; i++)
    {
        area += min(leftMaxArray[i], rightMaxArray[i]) - arr[i];
    }
    return area;
}
int main()
{
    int n;
    cout << "Enter the no. of Buildings:" << endl;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the height of Building:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = rainwaterHarvesting(arr, n);
    cout << "Area where Water is Stored:" << ans << endl;
    return 0;
}
