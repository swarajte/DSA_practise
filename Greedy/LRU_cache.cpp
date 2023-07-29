#include <bits/stdc++.h>
using namespace std;


// problem statement : https://practice.geeksforgeeks.org/problems/page-faults-in-lru5603/1
//theory : https://www.geeksforgeeks.org/lru-cache-implementation/
class Node
{
public:
    Node *next;
    Node *prev;
    int data;
    Node(int x)
    {
        next = NULL;
        prev = NULL;
        data = x;
    }
};


    unordered_map<int, Node *> mp;
    int count = 0;
    Node *head = new Node(-1);
    Node *tail = new Node(-1);
    void insert_head(int x)
    {
        Node *node = new Node(x);
        Node *temp = head->next;
        node->next = temp;
        temp->prev = node;
        node->prev = head;
        head->next = node;
        mp[x] = node;
    }
    void delete_node(Node *node)
    {
        mp.erase(node->data);
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete (node);
    }
    int pageFaults(int n, int c, int arr[])
    {
        tail->prev = head;
        head->next = tail;
        int count=0;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(arr[i]) != mp.end())
            {
                Node *temp = mp[arr[i]];
                delete_node(temp);
                insert_head(arr[i]);
            }
            else
            {
                count++;
                if (mp.size() < c)
                {
                    insert_head(arr[i]);
                }
                else
                {
                    delete_node(tail->prev);
                    insert_head(arr[i]);
                }
            }
        }
        return count;
    }

    int main()
    {

        return 0;
    }