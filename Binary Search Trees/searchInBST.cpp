#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
bool searchBST(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL)
        return false;
    if (root->data == k)
        return true;
    if (k < root->data)
        return searchBST(root->left, k);
    if (k > root->data)
        return searchBST(root->right, k);
    else
        return false;
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    int k;
    cout << "Enter Node which you want to search in BST:" << endl;
    cin >> k;
    bool ans = searchBST(root, k);
    if (ans)
        cout << "Yes it is Present in BST" << endl;
    else
        cout << "Not Present" << endl;
    return 0;
}