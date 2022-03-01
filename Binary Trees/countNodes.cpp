#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
int countNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout << "Total no. of Nodes: " << endl
         << countNodes(root) << endl;
    return 0;
}
