#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
pair<int, int> getMinandMax(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> ans;
        ans.first = INT_MAX;
        ans.second = INT_MIN;
        return ans;
    }
    pair<int, int> leftAns = getMinandMax(root->left);
    pair<int, int> rightAns = getMinandMax(root->right);
    int lmin = leftAns.first;
    int lmax = leftAns.second;
    int rmin = rightAns.first;
    int rmax = rightAns.second;
    int fmin = min(root->data, min(lmin, rmin));
    int fmax = max(root->data, max(lmax, rmax));
    pair<int, int> ans;
    ans.first = fmin;
    ans.second = fmax;
    return ans;
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    pair<int, int> ans = getMinandMax(root);
    cout << "Minimum Node of BinaryTree: " << ans.first << endl;
    cout << "Maximum Node of BinaryTree: " << ans.second << endl;
    return 0;
}