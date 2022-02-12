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

Node *constructBST(int preorder[], int *preIdx, int key, int min, int max, int n)
{
    if (*preIdx >= n)
        return NULL;

    Node *root = NULL;

    if (key < max && key > min)
    {
        root = new Node(key);
        *preIdx += 1;
        if (*preIdx < n)
        {
            root->left = constructBST(preorder, preIdx, preorder[*preIdx], min, key, n);
        }
        if (*preIdx < n)
        {
            root->right = constructBST(preorder, preIdx, preorder[*preIdx], key, max, n);
        }
    }

    return root;
}
void preorderPrint(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main()
{

    int preorder[] = {10, 2, 1, 13, 11};
    int n = 5;
    int preIdx = 0;

    Node *ans = constructBST(preorder, &preIdx, preorder[0], INT_MIN, INT_MAX, n);
    preorderPrint(ans);

    return 0;
}