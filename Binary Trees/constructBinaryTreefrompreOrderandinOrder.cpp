#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
BinaryTreeNode<int> *buildTree(int *pre, int *in, int preS, int preE, int inS, int inE)
{
    if (preS > preE || inS > inE)
        return NULL;
    int rootdata = pre[preS];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootdata)
        {
            rootIndex = i;
            break;
        }
    }
    int linS = inS;
    int linE = rootIndex - 1;
    int lpreS = preS + 1;
    int lpreE = linE - linS + lpreS;
    int rinS = rootIndex + 1;
    int rinE = inE;
    int rpreS = lpreE + 1;
    int rpreE = preE;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
    root->left = buildTree(pre, in, lpreS, lpreE, linS, linE);
    root->right = buildTree(pre, in, rpreS, rpreE, rinS, rinE);
    return root;
}
int main()
{
    int n;
    cout << "Enter size of InOrder and PreOrder:" << endl;
    cin >> n;
    int *pre = new int[n];
    int *in = new int[n];
    cout << "Enter Elements of PreOrder:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    cout << "Enter Elements of InOrder:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    cout << "\nTree Formed is:" << endl;
    BinaryTreeNode<int> *root = buildTree(pre, in, 0, n - 1, 0, n - 1);
    printLevelInNextLine(root);
    return 0;
}