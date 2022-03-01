#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
vector<Node *> levelWiseLinkedList(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return {};
    queue<BinaryTreeNode<int> *> pendingNode;
    pendingNode.push(root);
    pendingNode.push(NULL);
    Node *head = NULL;
    Node *tail = NULL;
    vector<Node *> output;
    while (!pendingNode.empty() && pendingNode.front() != NULL)
    {
        BinaryTreeNode<int> *front = pendingNode.front();
        pendingNode.pop();
        Node *newNode = new Node(front->data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
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
            output.push_back(head);
            head = NULL;
            tail = NULL;
        }
    }
    return output;
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    vector<Node *> ans = levelWiseLinkedList(root);
    cout << "\nBinary Tree in Level Wise Linked List:" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        Node *temp = ans[i];
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    return 0;
}