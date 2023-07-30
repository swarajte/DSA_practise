#include <bits/stdc++.h> 
using namespace std;

bool IsSorted(int arr[],int size){
    if(size==0 || size==1){
        return true;
    }

    if(arr[0]>arr[1]){
        return false;
    }
    else{
        bool ans=IsSorted(arr+1,size-1);
        return ans;
    }
}
int main()
{
    
    int arr[5]={1,2,3,4,5};
    if(IsSorted(arr,5)){
        cout<<"sorted "<<endl;
    }
    else{
        cout<<"not";
    }
    return 0;
}