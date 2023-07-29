#include <bits/stdc++.h>
using namespace std;

// solution : https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *BuildTree(node *root)
{
    int d;
    cout << "enter data of the node " << endl;
    cin >> d;
    root = new node(d);

    if (d == -1)
    {
        return NULL;
    }

    cout << "enter data of left node of " << d << endl;
    root->left = BuildTree(root->left);
    cout << "enter data of right node of " << d << endl;
    root->right = BuildTree(root->right);

    return root;
}

int CountNodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int ans = 1 + CountNodes(root->left) + CountNodes(root->right);
    return ans;
}

bool isCBT(node *root, int i, int count)
{
    // base case
    if (root == NULL)
    {
        return true;
    }

    if (i >= count)
    {
        return false;
    }
    else
    {
        bool leftans = isCBT(root->left, 2 * i + 1, count);
        bool rightans = isCBT(root->right, 2 * i + 2, count);
        return (leftans && rightans);
    }
}

bool isMaxheap(node *root)
{
    // leaf node
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }

    // having only single child (left child) as only right is not possible
    if (root->right == NULL)
    {
        if (root->data > root->left->data)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // both childern present
    else
    {
        bool left = isMaxheap(root->left);
        bool right = isMaxheap(root->right);
        return (root->data > root->left->data && root->data > root->right->data) && left && right;
    }
}

bool isHeap(node *tree)
{
    // code here
    int n = CountNodes(tree);
    int index = 0;
    if (isCBT(tree, index, n) && isMaxheap(tree))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    return 0;
}