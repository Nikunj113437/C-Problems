#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
int sumOfNodes(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum = sum + sumOfNodes(root->children[i]);
    }
    return sum;
}
int main()
{
    TreeNode<int> *root = takeInput();
    cout << "Sum of Nodes are: " << sumOfNodes(root) << endl;
    return 0;
}