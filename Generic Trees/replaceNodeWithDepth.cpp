#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
// TreeNode<int> *takeInput()
// {
//     int rootdata;
//     cout << "Enter root data:" << endl;
//     cin >> rootdata;
//     TreeNode<int> *root = new TreeNode<int>(rootdata);
//     queue<TreeNode<int> *> pendingNode;
//     pendingNode.push(root);
//     while (!pendingNode.empty())
//     {
//         TreeNode<int> *front = pendingNode.front();
//         pendingNode.pop();
//         int numchild;
//         cout << "Enter Number of children of " << front->data << ":" << endl;
//         cin >> numchild;
//         for (int i = 0; i < numchild; i++)
//         {
//             int childdata;
//             cout << "Enter " << i + 1 << "th child of " << front->data << ":" << endl;
//             cin >> childdata;
//             TreeNode<int> *child = new TreeNode<int>(childdata);
//             front->children.push_back(child);
//             pendingNode.push(child);
//         }
//     }
//     return root;
// }
// void printLevelWise(TreeNode<int> *root)
// {
//     queue<TreeNode<int> *> pendingNode;
//     pendingNode.push(root);
//     while (!pendingNode.empty())
//     {
//         TreeNode<int> *front = pendingNode.front();
//         pendingNode.pop();
//         cout << front->data << ": ";
//         for (int i = 0; i < front->children.size(); i++)
//         {
//             pendingNode.push(front->children[i]);
//             cout << front->children[i]->data;
//             if (i != front->children.size() - 1)
//                 cout << ",";
//         }
//     }
// }
void replaceNodeWithDepth(TreeNode<int> *root, int k)
{
    if (root == NULL)
        return;
    root->data = k;
    for (int i = 0; i < root->children.size(); i++)
    {
        replaceNodeWithDepth(root->children[i], k + 1);
    }
}
int main()
{
    TreeNode<int> *root = takeInput();
    replaceNodeWithDepth(root, 0);
    printLevelWise(root);
    return 0;
}