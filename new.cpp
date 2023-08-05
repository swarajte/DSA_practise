#include <bits/stdc++.h>
using namespace std;

// void printstack(stack<int> &st)
// {
//     while (st.size() != 0)
//     {
//         cout << st.top() << " ";
//         st.pop();
//     }
// }

// void insertinsortedst(stack<int> &st, int target)
// {
//     if (st.empty() || st.top() < target)
//     {
//         st.push(target);
//     }

//     int num = st.top();
//     st.pop();
//     insertinsortedst(st, target);
//     st.push(num);
// }

// void sort(stack<int> &st)
// {
//     if (st.empty())
//     {
//         return;
//     }
//     int num = st.top();
//     st.pop();
//     sort(st);
//     insertinsortedst(st, num);
// }

// bool getParity(unsigned int n)
// {
//     return __builtin_parity(n);
// }

// void countPalindromePaths(vector<int> &parent, string s)
// {
//     int n = parent.size();
//     // creating adj list
//     vector<pair<char, int>> adj[n];

//     for (int i = 0; i < n; i++)
//     {
//         if (parent[i] != -1)
//         {
//             adj[parent[i]].push_back({s[i], i});
//             adj[i].push_back({s[i], parent[i]});
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         cout << " adj list for " << i << endl;
//         for (int j = 0; j < adj[i].size(); j++)
//         {
//             cout << "(" << adj[i][j].first << "," << adj[i][j].second << ") ";
//         }
//         cout << endl;
//     }
// }

pair<int, int> maxcount(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    int maxcount = 0;
    int ele;
    for (auto it : mp)
    {
        if (it.second > maxcount)
        {
            maxcount = it.second;
            ele = it.first;
        }
    }
    pair<int, int> p = make_pair(maxcount, ele);
    return p;
}

bool isPossible(int mid, vector<int> &nums, int k)
{
    // count, element
    pair<int, int> p = maxcount(nums);
    if (p.first >= mid)
    {
        return true;
    }

    int cnt = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != p.second)
        {
            if (nums[i] - k <= p.second && p.second <= nums[i] + k)
            {
                cnt++;
            }
        }
        if (cnt == mid - p.first)
        {
            return true;
        }
    }
    return false;
}
int maximumBeauty(vector<int> &nums, int k)
{
    int s = 1;
    int e = nums.size();
    int mid = e + (s - e) / 2;
    int ans;

    while (s <= e)
    {
        if (isPossible(mid, nums, k))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid=s+(e-s)/2;
    }

    return ans;
}

int main()
{
    // // a = 5(00000101), b = 9(00001001)
    // int a = 1, b = 9;

    // // The result is 00000001
    // cout<<"a = " << a <<","<< " b = " << b <<endl;
    // cout << "a & b = " << (a & b) << endl;

    // // The result is 00001101
    // cout << "a | b = " << (a | b) << endl;

    // // The result is 00001100
    // cout << "a ^ b = " << (a ^ b) << endl;

    // // The result is 11111010
    // cout << "~a = " << (~a) << endl;

    // // The result is 00010010
    // cout<<"b << 1" <<" = "<< (b << 1) <<endl;

    // // The result is 00000100
    // cout<<"b >> 1 "<<"= " << (b >> 1 )<<endl;

    // to_string(int )  // for int to string
    // stoi(str)  .. from string to int

    // tarversing from beginning
    // map<int,int> mp;
    // mp.insert({5,50});
    // mp.insert({1,10});
    // mp.insert({2,20});

    // tarversing from beginning for ordered map
    // unordered_map<int,int> :: iterator it;
    // for(it=mp.begin(); it!=mp.end(); it++){
    //     cout<<it->first<<" : "<<it->second<<endl;
    // }

    // cout<<endl;

    // tarversing from end for ordered map
    // map<int,int>:: reverse_iterator ir;
    // for(ir=mp.rbegin(); ir!=mp.rend(); ir++){
    //     cout<<ir->first<<" : "<<ir->second<<endl;
    // }

    // if((getParity(2) == true &&  getParity(6)==true) || (getParity(2) == false &&  getParity(6)==false)){
    //     cout<<"true";
    // }
    // else{
    //     cout<<"false";
    // }

    // vector<int> parent={-1,0,0,1,1,2};
    // string s="acaabc";
    // countPalindromePaths(parent,s);

    // map<char,string> mp;
    // mp['2']="abc";
    // mp['3']="def";
    // mp['4']="ghi";
    // mp['5']="jkl";
    // mp['6']="mno";
    // mp['7']="pqrs";
    // mp['8']="tuv";
    // mp['9']="wxyz";

    int k=2;
    vector<int> nums={4,6,1,2};
    cout<<maximumBeauty(nums,k);

    return 0;
}
