// C++ program to find maximum sum from a subset of
// Nodes of binary tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree Node structure */
class Node
{
public:
    int data;
    Node* left, *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

pair<int, int> maxSumHelper(Node *root)
{
    if (root == NULL)
        return {0, 0};

    pair<int, int> l = maxSumHelper(root->left);
    pair<int, int> r = maxSumHelper(root->right);
    pair<int, int> sum;

    sum.first = root->data + l.second + r.second;
    sum.second = max(l.first, l.second) + max(r.first, r.second);

    return sum;
}

int getMaxSum(Node *root)
{
    pair<int, int> res = maxSumHelper(root);
    return max(res.first, res.second);
}

int main()
{
    Node *root= new Node(10);
    root->left= new Node(1);
    root->left->left= new Node(2);
    root->left->left->left= new Node(1);
    root->left->right= new Node(3);
    root->left->right->left= new Node(4);
    root->left->right->right= new Node(5);
    cout << getMaxSum(root);
    return 0;
}