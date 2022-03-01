#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
TreeNode<int> *maxNode(TreeNode<int> *root)
{
    if (root == NULL)
        return root;
    TreeNode<int> *max = new TreeNode<int>(root->data);
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *temp = maxNode(root->children[i]);
        if (temp->data > max->data)
            max = temp;
    }
    return max;
}
int main()
{
    TreeNode<int> *root = takeInput();
    cout << "Maximum node is: " << maxNode(root)->data << endl;
    return 0;
}
