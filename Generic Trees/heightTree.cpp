#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
int getHeight(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int temp = getHeight(root->children[i]);
        if (ans < temp)
            ans = temp;
    }
    return 1 + ans;
}
int main()
{
    TreeNode<int> *root = takeInput();
    cout << "Height of tree is: " << getHeight(root) << endl;
    printLevelWise(root);
    return 0;
}