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

void flattern(Node * root){

    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }

    if(root->left){
        flattern(root->left);
        Node * temp = root->right;
        root->right = root->left;
        root->left = NULL;


        Node * t = root->right;
        while(t->right){
            t = t->right;
        }
        t->right = temp;
    }

    flattern(root->right);

}

void inorderPrint(Node * root){
    if(root == NULL) return;
    
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
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

    flattern(root);
    inorderPrint(root);

    return 0;
}