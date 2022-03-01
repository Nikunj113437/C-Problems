#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
TreeNode<int> *nextLarger(TreeNode<int> *root, int x)
{
    if (root == NULL)
        return root;
    TreeNode<int> *ans = NULL;
    if (root->data > x)
        ans = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *temp = nextLarger(root->children[i], x);
        if (temp != NULL && ans == NULL)
            ans = temp;
        if (temp != NULL && temp->data < ans->data)
            ans = temp;
    }
    return ans;
}
int main()
{
    TreeNode<int> *root = takeInput();
    int x;
    cout << "Enter X:" << endl;
    cin >> x;
    TreeNode<int> *ans = nextLarger(root, x);
    cout << "Next Larger Element than " << x << " in Tree:" << endl;
    cout << ans->data;
    return 0;
}