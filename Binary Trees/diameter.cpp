#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> ans;
        ans.first = 0;
        ans.second = 0;
        return ans;
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;
    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> ans;
    ans.first = height;
    ans.second = diameter;
    return ans;
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    pair<int, int> ans = heightDiameter(root);
    cout << "Diameter of given BinaryTree:" << ans.second << endl;
    cout << "Height of given BinaryTree:" << ans.first << endl;
    return 0;
}