// mirror binaryTree is just a swapping of left child and right child

#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
void mirrorBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    BinaryTreeNode<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout << "Mirror of given BinaryTree:" << endl;
    printLevelWise(root);
    cout << endl
         << endl;
    mirrorBinaryTree(root);
    printLevelWise(root);
    return 0;
}