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
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void calc(Node *root, Node **first, Node **mid, Node **end, Node **prev)
{
    if (root == NULL)
        return;
    calc(root->left, first, mid, end, prev);

    if (*prev and root->data < (*prev)->data)
    {
        if (!*first)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *end = root;
        }
    }
    *prev = root;
    calc(root->right, first, mid, end, prev);
}

void restoreBST(Node *root)
{
    Node *first, *end, *mid, *prev;
    first = end = mid = prev = NULL;
    calc(root, &first, &mid, &end, &prev);

    if (first && end)
    {
        swap(&(first->data), &(end->data));
    }
    else if (first and mid)
    {
        swap(&(first->data), &(mid->data));
    }
}
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = new Node(6);
    root->left = new Node(9);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(13);
    inorder(root);
    cout << endl;
    restoreBST(root);
    inorder(root);

    return 0;
}