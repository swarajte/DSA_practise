#include <bits/stdc++.h>
using namespace std;

int compress(vector<char> &chars)
{

    int arr[26] = {0};
    for (int i = 0; i < chars.size(); i++)
    {
        int index = chars[i] - 'a';
        arr[index]++;
    }
    int size = 0;
    for (int i = 0; i < 26; i++)
    {
        char ch;
        if (arr[i] == 1)
        {
            size++;
        }
        else if (arr[i] > 1 && arr[i] < 10)
        {
            size = size + 2;
        }
        else if (arr[i] >= 10)
        {
            size++;
            int count = 0;
            int n=arr[i];
            while (n != 0)
            {
                n = n / 10;
                ++count;
            }
            size=size+count;
        }
    }

    return size;

}

int main()
{
    vector<char> chars;
    for (int i = 0; i < 7; i++)
    {
        char ch;
        cin >> ch;
        chars.push_back(ch);
    }
    int a = 0;
    
    cout<<"ans is "<<compress(chars);

    return 0;
}