#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
void preOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout << "PreOrder Traversal of BinaryTree:" << endl;
    preOrder(root);
    return 0;
}