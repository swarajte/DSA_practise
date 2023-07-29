#include <bits/stdc++.h> 
using namespace std;

int binarysearch(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    int mid=(start+end)/2;
    while(start<=end){
        if(arr[mid]==key){
            return mid+1;
        }

        if(arr[mid]<key){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=(start+end)/2;
    }

    return -1;
}
int main()
{
    int arr[6]={1,2,3,4,5,6};
    cout<<"position of key is "<<binarysearch(arr,6,522);

    return 0;
}