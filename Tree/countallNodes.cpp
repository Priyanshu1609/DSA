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

int nodes(Node *root)
{
    if (root == NULL)
        return 0;

    int l = 0, r = 0;
    l = nodes(root->left);
    r = nodes(root->right);
    return (l + r + 1);
}

int sumNodes(Node *root){
    if(root == NULL) return 0;

    int l = 0, r = 0;
    l = sumNodes(root->left);
    r = sumNodes(root->right);
    return(l + r + root->data);
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


int diameter (Node *root){
    if(root == NULL) return 0;

    int l = height(root->left);
    int r = height(root->right);
    
    int curr = l + r +1;

    int lDia = diameter(root->left);
    int rDia = diameter(root->right);

    return(max(curr, max(lDia, rDia)) );
}

int diameterOpt(Node * root, int * height){

    if(root== NULL) {
        *height = 0;
        return 0;
    }

    int lh= 0, rh=0;
    int lDia = diameterOpt(root->left, &lh);
    int rDia = diameterOpt(root->right, &rh);

    int currDia = lh + rh +1;
    *height = max(lh, rh) +1;

    return max(currDia, max(lDia, rDia));
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

    cout << nodes(root) << endl;
    cout << sumNodes(root) << endl;
    cout << diameter(root) << endl;

    int height =0;
    cout << diameterOpt(root, &height) << endl;

    return 0;
}