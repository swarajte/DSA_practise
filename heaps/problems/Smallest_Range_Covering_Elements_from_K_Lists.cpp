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

vector<int> smallestRange(vector<vector<int>> &nums)
{
    // create ans ka vector and minheap of type Node* for inserting elements
    vector<int> ans;
    priority_queue<node *, vector<node *>, compare> minheap;

    // create mini ans maxi and ansstart and ansend
    int mini = INT_MAX, maxi = INT_MIN;

    // insert first elements of all k vectors
    int k = nums.size();
    for (int i = 0; i < k; i++)
    {
        node *temp = new node(nums[i][0], i, 0);
        minheap.push(temp);
        mini = min(mini, temp->data);
        maxi = max(maxi, temp->data);
    }

    int ansstart = mini, ansend = maxi;

    // processing range
    while (!minheap.empty())
    {
        node *top = minheap.top();
        minheap.pop();
        // updating minimum
        mini = top->data;

        // updating minimum possible range
        if (maxi - mini < ansend - ansstart)
        {
            ansstart = mini;
            ansend = maxi;
        }

        int i = top->row;
        int j = top->col;
        int n = nums[i].size();

        // if possible (minimum node ka next is in range )updating maxi and     pushing in minheap
        if (j + 1 < n)
        {
            maxi = max(maxi, nums[i][j + 1]);
            node *next = new node(nums[i][j + 1], i, j + 1);
            minheap.push(next);
        }
        else
        {
            break;
        }
    }

    ans.push_back(ansstart);
    ans.push_back(ansend);
    return ans;
}

int main()
{

    return 0;
}