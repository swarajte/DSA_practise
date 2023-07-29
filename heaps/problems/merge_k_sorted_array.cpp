#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    int row;
    int col;

    node(int d, int i, int j)
    {
        this->data = d;
        this->row = i;
        this->col = j;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    // Write your code here.
    // first create ans vector and minheap of node * type
    vector<int> ans;
    priority_queue<node *, vector<node *>, compare> minheap;

    // push first elemnt of all k arrays
    for (int i = 0; i < k; i++)
    {
        node *temp = new node(kArrays[i][0], i, 0);
        minheap.push(temp);
    }

    // process for remaining elements and find min ele of k by minheap insert its data in ans and check for next element or node of that particular array
    while (!minheap.empty())
    {
        node *temp = minheap.top();
        ans.push_back(temp->data);
        minheap.pop();

        int i = temp->row;
        int j = temp->col;

        // checking boundry condition for next node of minimum  elemnent inserted in ans vector
        if (j + 1 < kArrays[i].size())
        {
            node *next = new node(kArrays[i][j + 1], i, j + 1);
            minheap.push(next);
        }
    }

    return ans;
}


int main()
{

    return 0;
}