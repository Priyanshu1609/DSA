#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
    Node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};

int maxPathSumUtil(Node *root, int &sum)
{
    if (root == NULL)
        return 0;

    int left = maxPathSumUtil(root->left, sum);
    int right = maxPathSumUtil(root->right, sum);

    int nodeMax = max(max(root->data, root->data + left + right), max(root->data + left, root->data + right));
    sum = max(sum, nodeMax);

    int singlePathSum = max(root->data, max(root->data + left, root->data + right));
    return singlePathSum;
}

int maxPathSum(Node *root)
{
    int sum = INT_MIN;
    maxPathSumUtil(root, sum);
    return sum;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << maxPathSum(root) << endl;

    return 0;
}