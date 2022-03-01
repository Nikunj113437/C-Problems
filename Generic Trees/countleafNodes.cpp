#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
int getLeafNodes(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    if (root->children.size() == 0)
        return 1;
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans = ans + getLeafNodes(root->children[i]);
    }
    return ans;
}
int main()
{
    TreeNode<int> *root = takeInput();
    cout << "Total Leaf Nodes :" << getLeafNodes(root) << endl;
    return 0;
}