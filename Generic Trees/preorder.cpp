// In preOrder first root get printed...after that child get printed

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
void preOrder(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preOrder(root->children[i]);
    }
}
int main()
{
    TreeNode<int> *root = takeInput();
    cout << "Traversal in PreOrder: " << endl;
    preOrder(root);
    return 0;
}