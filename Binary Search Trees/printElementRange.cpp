#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
// template <typename T>
// class BinaryTreeNode
// {
// public:
//     T data;
//     BinaryTreeNode<T> *left;
//     BinaryTreeNode<T> *right;
//     BinaryTreeNode(T data)
//     {
//         this->data;
//         this->left = NULL;
//         this->right = NULL;
//     }
//     ~BinaryTreeNode()
//     {
//         delete left;
//         delete right;
//     }
// };
// BinaryTreeNode<int> *takeInput()
// {
//     int rootdata;
//     cout << "Enter root data:" << endl;
//     cin >> rootdata;
//     if (rootdata == -1)
//         return NULL;
//     BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
//     BinaryTreeNode<int> *left = takeInput();
//     BinaryTreeNode<int> *right = takeInput();
//     root->left = left;
//     root->right = right;
//     return root;
// }
// BinaryTreeNode<int> *takeInputLevelWise()
// {
//     int rootdata;
//     cout << "Enter root data:" << endl;
//     cin >> rootdata;
//     if (rootdata == -1)
//         return NULL;
//     BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
//     queue<BinaryTreeNode<int> *> pendingNode;
//     pendingNode.push(root);
//     while (!pendingNode.empty())
//     {
//         BinaryTreeNode<int> *front = pendingNode.front();
//         pendingNode.pop();
//         int leftchild;
//         cout << "Enter left child of " << front->data << " :" << endl;
//         cin >> leftchild;
//         if (leftchild != -1)
//         {
//             BinaryTreeNode<int> *left = new BinaryTreeNode<int>(leftchild);
//             front->left = left;
//             pendingNode.push(left);
//         }
//         int rightchild;
//         cout << "Enter right child of " << front->data << " :" << endl;
//         cin >> rightchild;
//         if (rightchild != -1)
//         {
//             BinaryTreeNode<int> *right = new BinaryTreeNode<int>(rightchild);
//             front->right = right;
//             pendingNode.push(right);
//         }
//     }
//     return root;
// }
// void printTree(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//         return;
//     cout << root->data << ": ";
//     if (root->left != NULL)
//     {
//         cout << "L:" << root->left->data << " ";
//     }
//     if (root->right != NULL)
//     {
//         cout << "R:" << root->right->data << " ";
//     }
//     printTree(root->left);
//     printTree(root->right);
// }
// void printLevelWise(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//         return;
//     queue<BinaryTreeNode<int> *> pendingNode;
//     pendingNode.push(root);
//     while (!pendingNode.empty())
//     {
//         BinaryTreeNode<int> *front = pendingNode.front();
//         pendingNode.pop();
//         cout << front->data << ": ";
//         if (front->left == NULL)
//             cout << "-1"
//                  << " ";
//         if (front->left != NULL)
//         {
//             cout << "L:" << front->left->data << " ";
//             pendingNode.push(front->left);
//         }
//         if (front->right == NULL)
//             cout << "-1"
//                  << " ";
//         if (front->right != NULL)
//         {
//             cout << "R:" << front->right->data << " ";
//             pendingNode.push(root->right);
//         }
//     }
// }
// void printLevelInNextLine(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//         return;
//     queue<BinaryTreeNode<int> *> pendingNode;
//     pendingNode.push(root);
//     pendingNode.push(NULL);
//     while (!pendingNode.empty() && pendingNode.front() != NULL)
//     {
//         BinaryTreeNode<int> *front = pendingNode.front();
//         pendingNode.pop();
//         cout << front->data << " ";
//         if (front->left != NULL)
//         {
//             pendingNode.push(front->left);
//         }
//         if (front->right != NULL)
//         {
//             pendingNode.push(front->right);
//         }
//         if (pendingNode.front() == NULL && !pendingNode.empty())
//         {
//             pendingNode.pop();
//             pendingNode.push(NULL);
//             cout << endl;
//         }
//     }
// }
void elementsInRange(BinaryTreeNode<int> *root, int k1, int k2)
{
    if (root == NULL)
        return;
    if (root->data > k1 && root->data < k2)
    {
        elementsInRange(root->left, k1, k2);
        cout << root->data << " ";
        elementsInRange(root->right, k1, k2);
    }
    else if (k2 <= root->data)
    {
        elementsInRange(root->left, k1, k2);
        if (root->data == k2)
            cout << root->data << " ";
    }
    else if (k1 >= root->data)
    {
        if (root->data == k1)
            cout << root->data << " ";
        elementsInRange(root->right, k1, k2);
    }
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    int k1, k2;
    cout << "Enter range:" << endl;
    cin >> k1 >> k2;
    elementsInRange(root, k1, k2);
    return 0;
}
