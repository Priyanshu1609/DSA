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

Node *buildBST(int arr[], int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);

    root->left = buildBST(arr, start, mid - 1);
    root->right = buildBST(arr, mid + 1, end);

    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    int arr[] = {
        1,
        2,
        3,
        4,
        5,
    };
    Node * ans = buildBST(arr, 0, 4);
    inorder(ans);

    return 0;
}