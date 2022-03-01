#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
int getLargerNodes(TreeNode<int> *root, int x)
{
    if (root == NULL)
        return 0;
    int count = 0;
    if (root->data > x)
        count++;
    for (int i = 0; i < root->children.size(); i++)
    {
        count = count + getLargerNodes(root->children[i], x);
    }
    return count;
}
int main()
{
    TreeNode<int> *root = takeInput();
    int x;
    cout << "Enter X:" << endl;
    cin >> x;
    cout << "No. Of Larger Nodes than " << x << ": " << getLargerNodes(root, x);
    return 0;
}