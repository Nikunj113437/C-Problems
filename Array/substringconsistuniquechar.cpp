// we have to find longest substring that consist of unique characters in string using
// sliding window concept

#include <bits/stdc++.h>
using namespace std;
void substringConsistUniqueCharacter(string str)
{
    int i = 0, j = 0, l = 0;
    int start = i;
    int maxlen = INT_MIN;         // l represent length of substring...maxlen is max length of substring
    unordered_map<char, int> map; // map stored latest index of character of string
    while (j < str.length())
    {
        if (map.count(str[j]) > 0 && i <= map[str[j]])
        {
            i = map[str[j]] + 1;
            l = j - i;
        }
        l++;
        map[str[j]] = j; // map[str[j]]  represent latest index of character
        if (l > maxlen)
        {
            maxlen = l;
            start = i;
        }
        j++;
    }

    cout << start << " " << maxlen << endl;
    for (int i = start; i < start + maxlen; i++)
    {
        cout << str[i];
    }
}
int main()
{
    string str;
    cout << "Enter the string:" << endl;
    cin >> str;
    cout << "Longest substring consist of unique character:" << endl;
    substringConsistUniqueCharacter(str);
    return 0;
}
