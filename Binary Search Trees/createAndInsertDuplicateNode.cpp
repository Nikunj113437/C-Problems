#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
void insertDuplicateNode(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    insertDuplicateNode(root->left);
    insertDuplicateNode(root->right)
        BinaryTreeNode<int> *duplicate = new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int> *temp = root->left;
    root->left = duplicate;
    duplicate->left = temp;
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout << "After inserting Duplicate Node:" << endl;
    insertDuplicateNode(root);
    printLevelInNextLine(root);
    return 0;
}