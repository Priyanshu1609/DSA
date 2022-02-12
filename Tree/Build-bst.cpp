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

Node *buildBST(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }

    if (root->data > val)
    {
        root->left = buildBST(root->left, val);
    }
    else
    {
        root->right = buildBST(root->right, val);
    }
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//* search O(logN)
Node *searchBST(Node *root, int val)
{
    if (root == NULL)
        return NULL;

    if (root->data == val)
        return root;

    if (root->data > val)
        searchBST(root->left, val);

    searchBST(root->right, val);
}

Node *inorderSucc(Node *root)
{
    Node *curr = root;
    while (curr and curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node *deleteBST(Node *root, int key)
{

    if (key < root->data)
        root->left = deleteBST(root->left, key);

    else if (key > root->data)
        root->right = deleteBST(root->right, key);

    else
    {
        if (root)
        {
            if (root->left == NULL)
            {
                Node *temp = root->right;
                free(root);
                return temp;
            }
            if (root->right == NULL)
            {
                Node *temp = root->left;
                free(root);
                return temp;
            }
            Node *temp = inorderSucc(root->right);
            root->data = temp->data;
            root->right = deleteBST(root->right, temp->data);
        }
    }
    return root;
}

int main()
{
    vector<int> v = {5, 1, 3, 4, 2, 7};
    Node *root = NULL;
    root = buildBST(root, 5);

    for (int i = 1; i < v.size(); i++)
    {
        buildBST(root, v[i]);
    }
    // inorder(root);
    if (searchBST(root, 1) != NULL)
        cout << "exist" << endl;

    else
        cout << "doesnot exist" << endl;

    return 0;
}