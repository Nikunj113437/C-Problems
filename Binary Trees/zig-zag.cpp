#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
void zigZagTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    stack<BinaryTreeNode<int> *> s1;
    stack<BinaryTreeNode<int> *> s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            BinaryTreeNode<int> *top = s1.top();
            s1.pop();
            cout << top->data << " ";
            if (top->left != NULL)
            {
                s2.push(top->left);
            }
            if (top->right != NULL)
            {
                s2.push(top->right);
            }
        }
        cout << endl;
        while (!s2.empty())
        {
            BinaryTreeNode<int> *top = s2.top();
            s2.pop();
            cout << top->data << " ";
            if (top->right != NULL)
            {
                s1.push(top->right);
            }
            if (top->left != NULL)
            {
                s1.push(top->left);
            }
        }
        cout << endl;
    }
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout << "\nPrinting given Binary Tree in Zig-Zag Order:" << endl;
    zigZagTree(root);
    return 0;
}