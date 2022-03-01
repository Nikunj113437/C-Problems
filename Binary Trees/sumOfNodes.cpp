#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
int sumOfNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout << "Sum Of All Nodes: " << sumOfNodes(root) << endl;
    return 0;
}