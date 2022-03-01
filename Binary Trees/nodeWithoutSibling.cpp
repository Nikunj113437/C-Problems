#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
void nodeWithoutSibling(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right != NULL)
        cout << root->right->data << " ";
    if (root->left != NULL && root->right == NULL)
        cout << root->left->data << " ";
    nodeWithoutSibling(root->left);
    nodeWithoutSibling(root->right);
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout << "\nNodes Without Sibling are: " << endl;
    nodeWithoutSibling(root);
    return 0;
}