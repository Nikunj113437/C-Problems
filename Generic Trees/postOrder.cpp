#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
void postOrder(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    for (int i = 0; i < root->children.size(); i++)
    {
        postOrder(root->children[i]);
    }
    cout << root->data << " ";
}
int main()
{
    TreeNode<int> *root = takeInput();
    cout << "Traversing PostOrder: " << endl;
    postOrder(root);
    return 0;
}