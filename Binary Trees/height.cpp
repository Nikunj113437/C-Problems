#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
int getHeight(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout << "Height of BinaryTree is:" << endl
         << getHeight(root) << endl;
    return 0;
}