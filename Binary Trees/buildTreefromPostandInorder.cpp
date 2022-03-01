#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
BinaryTreeNode<int> *buildTree(int *post, int *in, int postS, int postE, int inS, int inE)
{
    if (postS > postE || inS > inE)
        return NULL;
    int rootdata = post[postE];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootdata)
        {
            rootIndex = i;
            break;
        }
    }
    int lpostS = postS;
    int linS = inS;
    int linE = rootIndex - 1;
    int lpostE = linE - linS + lpostS;
    int rpostS = lpostE + 1;
    int rpostE = postE - 1;
    int rinS = rootIndex + 1;
    int rinE = inE;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
    root->left = buildTree(post, in, lpostS, lpostE, linS, linE);
    root->right = buildTree(post, in, rpostS, rpostE, rinS, rinE);
    return root;
}
int main()
{
    int n;
    cout << "Enter size of InOrder and PostOrder:" << endl;
    cin >> n;
    int *post = new int[n];
    int *in = new int[n];
    cout << "Enter Elements of PostOrder:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
    }
    cout << "Enter Elements of InOrder:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    cout << "\nTree Formed is:" << endl;
    BinaryTreeNode<int> *root = buildTree(post, in, 0, n - 1, 0, n - 1);
    printLevelInNextLine(root);
    return 0;
}