#include <bits/stdc++.h> 
using namespace std;


char MaxOccurChar(string &s){
    int arr[26]={0};
    for (int i = 0; i < s.length(); i++)
    {
        char ch=s[i];
        int val=0;
        if(ch>='a' && ch<='z'){
            val = ch-'a';
        }
        else{
            val=ch-'A';
        }
        arr[val]++;
    }

    int maxi=-1;
    int ans=0;
    for (int i = 0; i < 26; i++)
    {
        if(arr[i]>maxi){
            ans=i;
            maxi=arr[i];
        }
    }

    char finalans='a'+ans;
    return finalans;
}
int main()
{
    string s;
    cin>>s;
    cout<<"most occuring character is "<< MaxOccurChar(s);
    return 0;
}