#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};
// Take Input but not level Wise
BinaryTreeNode<int> *takeInput()
{
    int rootdata;
    cout << "Enter root Node:" << endl;
    cin >> rootdata;
    if (rootdata == -1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
    BinaryTreeNode<int> *left = takeInput();
    BinaryTreeNode<int> *right = takeInput();
    root->left = left;
    root->right = right;
    return root;
}
// print binaryTree but not level wise
void print(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << ": ";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data;
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }
    print(root->left);
    print(root->right);
}
// take Input Level Wise----->Using Queue
BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootdata;
    cout << "Enter root data:" << endl;
    cin >> rootdata;
    if (rootdata == -1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int> *> pendingNode;
    pendingNode.push(root);
    while (!pendingNode.empty())
    {
        BinaryTreeNode<int> *front = pendingNode.front();
        pendingNode.pop();
        int leftChild;
        cout << "Enter left Child of " << front->data << ": " << endl;
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *left = new BinaryTreeNode<int>(leftChild);
            front->left = left;
            pendingNode.push(left);
        }
        int rightChild;
        cout << "Enter right child of " << front->data << ":" << endl;
        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *right = new BinaryTreeNode<int>(rightChild);
            front->right = right;
            pendingNode.push(right);
        }
    }
    return root;
}
// print BinaryTree Level Wise------->Using queue
void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> pendingNode;
    pendingNode.push(root);
    while (!pendingNode.empty())
    {
        BinaryTreeNode<int> *front = pendingNode.front();
        pendingNode.pop();
        cout << front->data << ": ";
        if (front->left == NULL)
            cout << "L:-1";
        if (front->left != NULL)
        {
            cout << "L:" << front->left->data << " ";
            pendingNode.push(front->left);
        }
        if (front->right == NULL)
            cout << "R:-1";
        if (front->right != NULL)
        {
            cout << "R:" << front->right->data << " ";
            pendingNode.push(front->right);
        }
    }
}
void printLevelInNextLine(BinaryTreeNode<int> *root)
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

// 1 2 3 4 5 6 7 8 -1 -1 9 -1 10 11 -1 12 13 14 15 -1 16 -1 17 -1 -1 -1 18 -1 -1 19 -1 -1 -1 -1 20 -1 -1 -1 -1 -1 -1

// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1