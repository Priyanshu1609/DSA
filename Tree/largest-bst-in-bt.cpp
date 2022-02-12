#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
struct Info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBSTinBT(Node *root)
{
    if (root == NULL)
        return {0, INT_MIN, INT_MAX, 0, true};

    if (root->left == NULL and root->right == NULL)
        return {1, root->data, root->data, 1, true};

    Info left = largestBSTinBT(root->left);
    Info right = largestBSTinBT(root->right);

    Info curr;
    curr.size = 1 + left.size + right.size;
    if (left.isBST && right.isBST && root->data < right.min && root->data > left.max)
    {
        curr.isBST = true;
        curr.min = min(left.min, min(right.min, root->data));
        curr.max = max(left.max, max(right.max, root->data));

        curr.ans = curr.size;
        return curr;
    }
    curr.ans = max(left.ans, right.ans);
    curr.isBST = false;
    return curr;
}

int main()
{
    Node *root = new Node(15);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(5);
    cout << largestBSTinBT(root).ans;
    return 0;
}