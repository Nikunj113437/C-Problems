// Print in level wise order int next line

#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
void displayLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> pendingNode;
    pendingNode.push(root);
    pendingNode.push(NULL);
    while (!pendingNode.empty() && pendingNode.front() != NULL)
    {
        BinaryTreeNode<int> *front = pendingNode.front();
        pendingNode.pop();
        cout << front->data << " ";
        if (front->left != NULL)
        {
            pendingNode.push(front->left);
        }
        if (front->right != NULL)
        {
            pendingNode.push(front->right);
        }
        if (pendingNode.front() == NULL && !pendingNode.empty())
        {
            pendingNode.pop();
            pendingNode.push(NULL);
            cout << endl;
        }
    }
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout << "Printing BinaryTree in Level Wise:" << endl;
    displayLevelWise(root);
    return 0;
}