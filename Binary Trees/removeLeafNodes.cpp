#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
BinaryTreeNode<int> *removeLeafNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return root;
    if (root->left == NULL && root->right == NULL)
        return NULL;
    BinaryTreeNode<int> *leftAns = removeLeafNodes(root->left);
    BinaryTreeNode<int> *rightAns = removeLeafNodes(root->right);
    root->left = leftAns;
    root->right = rightAns;
    return root;
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    BinaryTreeNode<int> *ans = removeLeafNodes(root);
    cout << "\n\nAfter removing Leaf Nodes:" << endl;
    printLevelWise(ans);
    return 0;
}