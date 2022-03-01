#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
void inOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout << "InOrder Traversal of Binary Tree:" << endl;
    inOrder(root);
    return 0;
}