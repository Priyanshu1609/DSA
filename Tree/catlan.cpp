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

int catlan(int n)
{

    if (n <= 1)
        return 1;

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += catlan(i) * catlan(n - i - 1);
    }

    return res;
}

vector<Node *> constructTrees(int start, int end)
{
    vector<Node *> trees;
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }
    for (int i = start; i <= end; i++)
    {
        vector<Node *> left = constructTrees(start, i - 1);
        vector<Node *> right = constructTrees(i + 1, end);

        for (int j = 0; j < left.size(); j++)
        {
            Node *leftTree = left[j];
            for (int k = 0; k < right.size(); k++)
            {
                Node *rightTree = right[k];
                Node *node = new Node(i);
                node->left = leftTree;
                node->right = rightTree;
                trees.push_back(node);
            }
        }
    }
    return trees;
}
void inorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
}

int main()
{
    vector<Node *> totalTrees = constructTrees(1, 3);
    for (int i = 0; i < totalTrees.size(); i++)
    {
        cout << i + 1 << ": ";
        inorder(totalTrees[i]);
        cout << endl;
    }

    return 0;
}