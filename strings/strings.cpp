#include <bits/stdc++.h>
// #define int long longtypedef long long ll;
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

int main()
{
    string str = "";
    string s = "hello";
    string space = " 3";
    reversebydoublepointer(s);
    str.append(s);
    str.append(space);
    str.push_back('l');
    cout << str;
    // cout<<endl;
    // string temp="";
    // for (int i = 0; i <str.size(); i++)
    // {
    //     if (str[i] != ' ' && str[i] != '\0')
    //     {
    //         temp.push_back(str[i]);
    //     }
    //     // else{
    //     //     reversebydoublepointer(temp);
    //     //     result.append(temp);
    //     //     result.append(space);
    //     //     temp.clear();
    //     // }
    // }
    // cout<<"**********************"<<endl;
    // cout<<temp;
    return 0;
}