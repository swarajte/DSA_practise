#include <bits/stdc++.h>
using namespace std;

// solution : https://www.youtube.com/watch?v=ho4gTCr0QSk
// question:- we have to find the next lexographic premutaion of given array that is lets assume nums=[1,2,3] therefore next permutaion is [1,3,2] all sets of permuation in sorted order is [1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]..... here we can observe that [3,2,1] is the last permutation so ans for this type of decreasing input will be first permution or sorted wala....

// for permutation other than last following should be the approach:

// suppose nums=[7,2,5,3,1]   if we observe due to 2 our array is not strictly decreasing otherwise it would be simple.....so we have to swap 2 with next closer greater number in remaining array i.e [5,3,1] to make [7,3,....]  here closest is 3 so swap 2 with 3 then arrange remaining in ascending order like [1 2 5]  so the ans will be [7,3,1,2,5]

// OR simple next_permutation=(nums.begin(),nums.end()); and done

// inft pt=inflection point
void nextPermutation(vector<int> nums,int &infpt)
{
    int n=nums.size();
    
    for(int i=n-1; i>=0; i--){
        if(nums[i]>nums[i-1]){
            infpt=i;
            break;
        }
    }

    if(infpt==0){
        sort(nums.begin(),nums.end());
        
    }
    else{
        int to_swap=nums[infpt-1];
        int mini=INT_MAX;
        for(int i=infpt; i<n; i++){
            if(nums[i]-to_swap>0) {
                int temp=nums[i];               // finding number to be swapped with closest
                nums[i]=nums[infpt-i];
                nums[infpt-i]=temp;
            }                               
        }

        sort(nums.begin()+infpt,nums.end());
        
    }
}

int main()
{
    vector<int> nums={7,2,5,3,1};
    
    int inft=0;
    nextPermutation(nums,inft);
    cout<<inft<<endl;
    for (int i = 0; i < nums.size() ; i++)
    {
        cout<<nums[i]<<" ";
    }

    return 0;
}