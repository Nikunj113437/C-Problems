#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
void printNodesUptoLevelK(TreeNode<int> *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printNodesUptoLevelK(root->children[i], k - 1);
    }
}
int main()
{
    int k;
    TreeNode<int> *root = takeInput();
    cout << "Enter the depth:" << endl;
    cin >> k;
    cout << "Nodes at depth " << k << " :" << endl;
    printNodesUptoLevelK(root, k);
    return 0;
}