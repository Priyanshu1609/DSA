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

bool check(Node *root, Node *max, Node *min)
{
    if (!root)
        return true;

    if (min && root->data <= min->data)
        return false;

    if (max && root->data >= max->data)
        return false;

    bool l = check(root->left, root, min);
    bool r = check(root->right, max, root);

    return l && r;
}

int main()
{
    Node *root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(7);

    cout << check(root, NULL, NULL);

    return 0;
}