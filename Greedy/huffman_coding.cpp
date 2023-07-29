#include <bits/stdc++.h> 
using namespace std;

// problem statement= https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
class cmp
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};
class Solution
{
public:
    void traverse(Node *root, vector<string> &ans, string temp)
    {
        // base case
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(temp);
            return;
        }
        traverse(root->left, ans, temp + '0');
        traverse(root->right, ans, temp + '1');
    }
    vector<string> huffmanCodes(string s, vector<int> f, int n)
    {
        priority_queue<Node *, vector<Node *>, cmp> pq;

        for (int i = 0; i < n; i++)
        {
            Node *temp = new Node(f[i]);
            pq.push(temp);
        }
        while (pq.size() > 1)
        {
            Node *left = pq.top();
            pq.pop();

            Node *right = pq.top();
            pq.pop();

            Node *newNode = new Node(left->data + right->data);
            newNode->left = left;
            newNode->right = right;
            pq.push(newNode);
        }

        Node *root = pq.top();
        vector<string> ans;
        string temp = "";
        traverse(root, ans, temp);
        return ans;
    }
};

int main()
{

    return 0;
}