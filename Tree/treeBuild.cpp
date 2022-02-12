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

int Search(int inorder[], int start, int end, int curr)
{

    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
            return i;
    }

    return -1;
}

Node *buildTreePre(int preorder[], int inorder[], int start, int end)
{
    if (start > end)
        return NULL;

    static int idx = 0;
    int curr = preorder[idx];
    Node *node = new Node(curr);
    idx++;

    if (start == end)
        return node;

    int pos = Search(inorder, start, end, curr);
    node->left = buildTreePre(preorder, inorder, start, pos - 1);
    node->right = buildTreePre(preorder, inorder, pos + 1, end);

    return node;
}
Node *buildTreePost(int postorder[], int inorder[], int start, int end)
{
    if (start > end)
        return NULL;

    static int idx = 4;
    int curr = postorder[idx];
    Node *node = new Node(curr);
    idx--;

    if (start == end)
        return node;

    int pos = Search(inorder, start, end, curr);
    node->right = buildTreePost(postorder, inorder, pos + 1, end);
    node->left = buildTreePost(postorder, inorder, start, pos - 1);

    return node;
}

void inorderPrint(struct Node *root)
{
    if (root == NULL)
        return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}
void postorderPrint(struct Node *root)
{
    if (root == NULL)
        return;
    postorderPrint(root->left);
    postorderPrint(root->right);
    cout << root->data << " ";
}

int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int postorder[] = {4, 2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};
    //struct Node *ans = buildTreePre(preorder, inorder, 0, 4);
    struct Node *ans = buildTreePost(postorder, inorder, 0, 4);
    postorderPrint(ans);

    return 0;
}