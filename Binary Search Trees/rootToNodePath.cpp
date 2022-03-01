#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
vector<int> *getRootToNodePath(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL)
        return NULL;
    if (k == root->data)
    {
        vector<int> *v;
        v->push_back(root->data);
        return v;
    }
    vector<int> *leftans = getRootToNodePath(root->left, k);
    if (leftans != NULL)
    {
        leftans->push_back(root->data);
        return leftans;
    }

    vector<int> *rightans = getRootToNodePath(root->right, k);
    if (rightans != NULL)
    {
        rightans->push_back(root->data);
        return rightans;
    }
    else
        return NULL;
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    int k;
    cout << "Enter Node:" << endl;
    cin >> k;
    vector<int> *ans = getRootToNodePath(root, k);
    cout << "\nRoot to Node Path is:" << endl
         << "< ";
    for (int i = 0; i < ans->size(); i++)
    {
        cout << ans->at(i) << " ";
    }
    cout << " >";
    return 0;
}