#include <bits/stdc++.h>
using namespace std;

int MinimumCost(string str)
{
    if (str.length() % 2 == 1)
    {
        return -1;
    }
    stack<char> stk;
    for (int i = 0; i < str.length(); i++)

    {
        char ch = str[i];
        if (ch == '{')
        {
            stk.push(ch);
        }
        else
        {
            if (!stk.empty() && stk.top() == '{')
            {
                stk.pop();
            }
            else
            {
                stk.push(ch);
            }
        }
    }

    int a = 0, b = 0;

    while(!stk.empty())
    {
        if (stk.top() == '{')
        {
            a++;
        }
        else
        {
            b++;
        }
    }

    return (((a + 1) / 2) + ((b + 1) / 2));
}
int main()
{
    string str = "{{{{";

    cout << MinimumCost(str);
    return 0;
}