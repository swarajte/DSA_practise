#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    // exclude ka call
    solve(nums, output, index + 1, ans);

    // include ka call
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index + 1, ans);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans=subsets(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<"{";
        for(int j=0; j<ans[i].size(); j++){
            if(j==ans[i].size()-1)
                cout<<ans[i][j];
            else
                cout<<ans[i][j]<<",";
        }
        cout<<"}"<<endl;
    }
    

    return 0;
}
