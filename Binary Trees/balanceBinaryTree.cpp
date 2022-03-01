#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
int getHeight(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + max(getHeight(root->left), getHeight(root->right));
}
bool isBalanced(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    if (isBalanced(root->left) && isBalanced(root->right))
    {
        int lH = getHeight(root->left);
        int rH = getHeight(root->right);
        if (lH - rH <= 1 || rH - lH <= 1)
            return true;
        else
            return false;
    }
    else
        return false;
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    bool ans = isBalanced(root);
    if (ans)
        cout << "\nGiven BinaryTree is Balanced" << endl;
    else
        cout << "\nGiven BinaryTree is not Balanced" << endl;
    return 0;
}