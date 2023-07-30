#include <bits/stdc++.h>
using namespace std;

// question: return the largest palinfrome present in the given string 



// approach 1: find all possible substrings and check for palindrome if yes then check for maximum length and return maximum wala substring 
bool check_palindrome(string &s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
string longestPalindrome_approach_1(string s)
{

    if (s.size() <= 1)
    {
        return s;
    }
    int starting_index = 0;
    int max_len = 0;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            if (check_palindrome(s, i, j))
            {
                if (j - i + 1 > max_len)
                {
                    max_len = j - i + 1;
                    starting_index = i;
                }
            }
        }
    }

    return s.substr(starting_index, max_len);
}

// approach 2: 

int main()
{
    string s="babad";
    cout<<longestPalindrome_approach_1(s);
    return 0;
}