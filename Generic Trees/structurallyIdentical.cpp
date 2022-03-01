#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
bool structurallyIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    if (root1->children.size() != root2->children.size())
        return false;
    if (root1->data != root2->data)
        return false;
    for (int i = 0; i < root1->children.size(); i++)
    {
        bool ans = structurallyIdentical(root1->children[i], root2->children[i]);
        if (!ans)
            return false;
    }
    return true;
}
int main()
{
    cout << "Enter 1st Tree:" << endl;
    TreeNode<int> *root1 = takeInput();
    cout << "Enter 2nd Tree:" << endl;
    TreeNode<int> *root2 = takeInput();
    bool ans = structurallyIdentical(root1, root2);
    if (ans)
        cout << "Structurally Identical" << endl;
    else
        cout << "Not Structurally Identical" << endl;
    return 0;
}