#include <bits/stdc++.h>
using namespace std;

bool checkpalindrome(string &str, int s, int e)
{
    if (s > e)
    {
        return true;
    }
    else
    {
        if (str[s] != str[e])
        {
            return false;
        }
        s++;
        e--;
        return checkpalindrome(str,s,e);
    }
}
int main()
{
    string str;
    cout << "enter string to be reversed " << endl;
    cin >> str;
    int s = 0;
    int e = str.length() - 1;

    if (checkpalindrome(str, s, e))
    {
        cout << "it is palindrome" << endl;
    }
    else
    {
        cout << "not a palindrome";
    }



    return 0;
}