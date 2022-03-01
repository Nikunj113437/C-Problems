// #include <bits/stdc++.h>
// using namespace std;
// int missingPositiveNo(int *arr, int n)
// {
//     unordered_map<int, int> map;
//     for (int i = 0; i < n; i++)
//         map[arr[i]]++;
//     for (int i = map.begin(); i != map.end(); i++)
//     {
//         if (map[i] == 0)
//         {
//             if (i > 0)
//                 return i->first;
//         }
//     }
//     return -1;
// }
// int main()
// {
//     int n;
//     cout << "Enter size of Array:" << endl;
//     cin >> n;
//     int *arr = new int[n];
//     cout << "Enter Elements of Array:" << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int ans = missingPositiveNo(arr, n);
//     if (ans != -1)
//     {
//         cout << "Smallest Positive no. which is missing in Array:" << ans << endl;
//     }
//     else
//         cout << "No such smallest positive no. found" << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 1, 2, 1, 1, 3, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    map<int, int> m;
    for (int i = 0; i < n; i++)
        m[arr[i]]++;

    cout << " Element Frequency" << endl;
    for (auto i = m.begin(); i != m.end(); i++)
        cout << i->first << "      " << i->second
             << endl;

    return 0;
}