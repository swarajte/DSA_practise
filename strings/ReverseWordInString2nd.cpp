#include <bits/stdc++.h> 
using namespace std;

void reversebydoublepointer(string &a)
{
    int s = 0;
    int e = a.length() - 1;
    while (s <= e)
    {
        swap(a[s], a[e]);
        s++;
        e--;
    }
}

string reverseWords(string &s){

    string temp=""; 
    string result="";
    string space=" ";
    for (int i = 0; i < s.size()+1; i++)
    {
        if(s[i]!=' ' && i!=s.size()){
            temp.push_back(s[i]);
        }
        else{
            reversebydoublepointer(temp);
            result.append(temp);
            result.append(space);
            temp.clear();
        }

    }

    // result.pop_back();
    return result;
}


int main()
{   
    string a="my name swaraj llll";
    string result="hello";
    result=reverseWords(a); 
    cout<<result;
    return 0;
}