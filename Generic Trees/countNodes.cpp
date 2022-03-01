#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
TreeNode<int> *takeInput()
{
    int rootdata;
    cout << "Enter root data:" << endl;
    cin >> rootdata;
    TreeNode<int> *root = new TreeNode<int>(rootdata);
    queue<TreeNode<int> *> pendingNode;
    pendingNode.push(root);
    while (!pendingNode.empty())
    {
        TreeNode<int> *front = pendingNode.front();
        pendingNode.pop();
        int numchild;
        cout << "Enter number of Children:" << endl;
        cin >> numchild;
        for (int i = 0; i < numchild; i++)
        {
            int childdata;
            cout << "Enter " << i + 1 << "th child of " << front->data << ":" << endl;
            cin >> childdata;
            TreeNode<int> *child = new TreeNode<int>(childdata);
            front->children.push_back(child);
            pendingNode.push(child);
        }
    }
    return root;
}
void printLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<TreeNode<int> *> pendingNode;
    pendingNode.push(root);
    while (!pendingNode.empty())
    {
        TreeNode<int> *front = pendingNode.front();
        pendingNode.pop();
        cout << front->data << ": ";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data;
            pendingNode.push(front->children[i]);
            if (i != front->children.size() - 1)
                cout << ",";
        }
        cout << endl;
    }
}
int countNodes(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans = ans + countNodes(root->children[i]);
    }
    return ans;
}
int main()
{
    TreeNode<int> *root = takeInput();
    cout << "No. of Nodes are :" << countNodes(root) << endl;
    return 0;
}