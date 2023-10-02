// Getting started with tree
#include <bits/stdc++.h>
using namespace std;

// binary tree
struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key = k;
        left = NULL;
        right = NULL;
    }
};

// Preorder Tree Traversal (root left right)
void printPreorderTree(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        printPreorderTree(root->left);
        printPreorderTree(root->right);
    }
    return;
}



int main()
{
    // non empty tree
    Node *root_two = new Node(10);
    root_two->left = new Node(20);
    root_two->right = new Node(30);

    // defining value for sub node
    root_two->left->left = new Node(40);
    root_two->left->right = new Node(50);
    root_two->left->right->left = new Node(70);
    root_two->left->right->right = new Node(80);
    root_two->right->right = new Node(60);
    cout << "Preorder Tree Traversal" << endl;
    printPreorderTree(root_two);
    cout << endl;

    return 0;
}
