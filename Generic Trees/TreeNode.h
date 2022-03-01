#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;
    TreeNode(T data)
    {
        this->data = data;
    }
};
TreeNode<int> *takeInput()
{ // take input level wise
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
        cout << "Enter number of Children of " << front->data << ":" << endl;
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
// 1 3 2 3 4 2 5 6 0 1 7 2 8 9 1 10 2 11 12 0 0 0 0 1 13 1 14 0