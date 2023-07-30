#include <bits/stdc++.h> 
using namespace std;

int partition(int arr[],int s,int e){
    int pivot=arr[s];
    int cnt=0;
    for (int i = s+1; i <= e; i++)
    {
        if(arr[i]<=pivot){
            cnt++;
        }
    }

    int pivotindex=s+cnt;
    swap(arr[s],arr[pivotindex]);

    int i=s,j=e;
    while(i<pivotindex && j>pivotindex){
        while(arr[i]<arr[pivotindex]){
            i++;
        }
        while(arr[j]>arr[pivotindex]){
            j--;
        }
        if(i<pivotindex && j>pivotindex)
            swap(arr[i],arr[j]);
    } 

    return pivotindex;
}


void quicksort(int*arr,int s,int e){
    if(s>=e){
        return;
    }

    int p=partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}

int main()
{
    
    int arr[5]={40,10,50,20,30};
    int n=5;
    int s=0;
    int e=4;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";   
    }
    cout<<endl;
    quicksort(arr,s,e);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";   
    }

    return 0;
}