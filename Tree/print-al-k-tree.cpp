#include <bits/stdc++.h>

using namespace std;

// binary tree node
struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void solve(Node *root, int k, int sum, vector<int> &path)
{
    if (!root)
        return;

    path.push_back(root->data);

    sum += root->data;
    if (sum == k)
    {
        for (int j = 0; j < path.size(); j++)
        {
            cout << path[j] << " ";
        }
        cout << endl;
    }
    solve(root->left, k, sum, path);
    solve(root->right, k, sum, path);
    path.pop_back();
}
void printPaths(Node *root, int sum)
{
    vector<int> path;
    solve(root, sum, 0, path);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);

    int k = 5;
    printPaths(root, k);
    return 0;
}