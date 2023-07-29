#include <bits/stdc++.h> 
using namespace std;

int solve_recur(int index,int target,vector<int> &arr){
    // if target is found
    if(target==0){
		return 1;
    }

    // if recursion after recursion size reduces to 1 and if that single element is equal to target true else false
    if(index==0){
        if(arr[index]==target){
			return 1;
        }
        else{
            return 0;
        }
    }

	int exclude=solve_recur(index-1, target, arr);
	int include=0;
	if(target>=arr[index])	
	{
		include=solve_recur(index-1,target-arr[index] ,arr);
	}

	return exclude+include;
}
int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
	return solve_recur(n-1,k,arr);

    // find memoisation and tabulation accordingly
}
int main()
{

    return 0;
}