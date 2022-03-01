// open bracket comes when noOfOpen brackets <n
// closing Bracket comes when no Of closing Bracket < no Of Open Bracket

#include <bits/stdc++.h>
using namespace std;
void validBracketPair(int n, int i, int noOfOpenBracket, int noOfClosingBracket, string ans)
{
    if (i == 2 * n)
    {
        cout << ans << endl;
    }
    if (noOfOpenBracket < n)
    {
        validBracketPair(n, i + 1, noOfOpenBracket + 1, noOfClosingBracket, ans + "(");
    }
    if (noOfClosingBracket < noOfOpenBracket)
    {
        validBracketPair(n, i + 1, noOfOpenBracket, noOfClosingBracket + 1, ans + ")");
    }
}
int main()
{
    int n; // n represent that in 1 pair n no. of pairs are present...ie n opening
    // bracket and n closing bracket
    cout << "Enter n:" << endl;
    cin >> n;
    string output = "";
    validBracketPair(n, 0, 0, 0, output);
    return 0;
}