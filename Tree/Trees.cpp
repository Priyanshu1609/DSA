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

void preorder(struct Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(struct Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int height(struct Node *root)
{
    int l = 0, r = 0;
    if (root == NULL)
        return 0;

    l = height(root->left);
    r = height(root->right);

    return (max(l, r) + 1);
}

int Max(struct Node *root)
{
    int a = 0, b = 0;
    if (root == NULL)
        return -1;

    a = Max(root->left);
    b = Max(root->right);
    return (max(root->data, max(a, b)));
}

int Min(struct Node *root)
{
    int a = 0, b = 0;
    if (root == NULL)
        return INT_MAX;

    a = Min(root->left);
    b = Min(root->right);
    return (min(root->data, min(a, b)));
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
    // preorder(root);
    // cout << endl;
    // inorder(root);
    // cout << endl;
    // postorder(root);
    cout << height(root) << endl;
    cout << Min(root) << endl;
    cout << Max(root) << endl;

    return 0;
}