// in this problem...each character of string has two option....
// either it is part of subset or not...so thats why we maintain empty string ans

#include <bits/stdc++.h>
using namespace std;
void printSubsetsOfString(string str, string ans)
{
    if (str.size() == 0)
    {
        cout << "{" << ans << "}"
             << " ";
        return;
    }
    printSubsetsOfString(str.substr(1), ans + str[0]); // if that character is the part of subset
    printSubsetsOfString(str.substr(1), ans);          // if it is not part of subset
}
int main()
{
    string str;
    string ans = "";
    cout << "Enter the String:" << endl;
    cin >> str;
    cout << "Subsets of given String:" << endl;
    printSubsetsOfString(str, ans);
    return 0;
}