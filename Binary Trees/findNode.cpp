#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
bool findNode(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
        return false;
    if (root->data == x)
        return true;
    if (root->left != NULL)
    {
        bool ans1 = findNode(root->left, x);
        if (ans1)
            return true;
    }
    if (root->right != NULL)
    {
        bool ans2 = findNode(root->right, x);
        if (ans2)
            return true;
    }
    return false;
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    int x;
    cout << "Enter the node which you want to find:" << endl;
    cin >> x;
    bool ans = findNode(root, x);
    if (ans)
        cout << "Yes it is Present in given Binary Tree" << endl;
    else
        cout << "No it is not Present" << endl;
    return 0;
}