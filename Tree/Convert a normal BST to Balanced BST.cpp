#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void inorder(Node *root, vector<Node *> &path)
{
    if (root == NULL)
        return;

    inorder(root->left, path);
    path.push_back(root);
    inorder(root->right, path);
}

Node *buildBST(vector<Node *> path, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    Node *root = (path[mid]);

    root->left = buildBST(path, start, mid - 1);
    root->right = buildBST(path, mid + 1, end);

    return root;
}
void preOrder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(8);
    root->left->left = new Node(7);
    root->left->left->left = new Node(6);
    root->left->left->left->left = new Node(5);
    vector<Node *> path;

    inorder(root, path);

    Node *ans = buildBST(path, 0, 4);
    preOrder(ans);

    return 0;
}