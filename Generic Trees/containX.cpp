#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
bool containX(TreeNode<int> *root, int x)
{
    if (root == NULL)
        return false;
    if (x == root->data)
        return true;
    for (int i = 0; i < root->children.size(); i++)
    {
        bool ans = containX(root->children[i], x);
        if (ans)
            return true;
    }
    return false;
}
int main()
{
    TreeNode<int> *root = takeInput();
    int x;
    cout << "Enter X:" << endl;
    cin >> x;
    bool ans = containX(root, x);
    if (ans)
        cout << "It is Present" << endl;
    else
        cout << "Not Present" << endl;
    return 0;
}