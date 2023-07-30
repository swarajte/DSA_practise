#include <bits/stdc++.h>
using namespace std;

// preparing maping for every element in nums2 of next greater element by stack and starting from nums2.size()-1 i.e from last.....if stack is empty we will map nums2[i] with -1 and push nums2[i] in stack.....if elements are present greater than nums2[i] then we will map nums2[i] with stack.top and push nums2[i] in stack.....if elemnte are present but not greater than nums2[i] we will pop until top>nums2[i] and then we will map nums2[i] with top and push nums2[i]....
// ......................................................................................
// after all this mapping we will simply make nums1[i]=map[nums1[i]] and return nums1

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    // since there are no duplicates, we can store them in a map;

    vector<int> res(nums1.size(), -1); // to be returned, initialize it with -1.
    stack<int> st;
    unordered_map<int, int> umap;

    for (int i = 0; i < nums2.size(); i++)
    {
        int element = nums2[i];

        while (!st.empty() && element > st.top())
        {
            // NGE of st.top() is element

            umap[st.top()] = element;
            st.pop();
        }

        st.push(element);
    }

    for (int i = 0; i < nums1.size(); i++)
    {
        int ele = nums1[i];

        if (umap.find(ele) != umap.end())
        {
            int nge = umap[ele];
            res[i] = nge; // push NGE of desired element
        }
    }

    return res;
}

int main()
{

    return 0;
}