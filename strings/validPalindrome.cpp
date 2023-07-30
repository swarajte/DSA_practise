// we are given string say s = "A man, a plan, a canal: Panama" here first we have to convert all uppercase letters to lowercase and then delete all the non alphanumeric values (characters which are not alphabets or numbers) then check for palindrome

#include <bits/stdc++.h> 
using namespace std;

bool alphanumericCheck(char ch){
    if(ch>='a' && ch<='z'||ch>='A' && ch<='Z'||ch>='0' && ch<='9'){
        return true;
    }
    return false;
}

bool checkpalindrome(string &s){
    int st=0;
    int e=s.length()-1;
    while(st<=e){
        if(s[st]!=s[e]){
            return false;
        }
        st++;
        e--;
    }
    return true;
}

char toLowerCase(char ch){
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')){
        return ch;
    }
    else{
        char temp=ch-'A'+'a';
        return temp;
    }
}
bool IsValidPalindrome(string &s){
    //removing non - alphanumeric values
    string temp="";
    for (int i = 0; i < s.length(); i++)
    {
        if(alphanumericCheck(s[i])){
            temp.push_back(s[i]);
        }
    }

    // converting to lowercase
    for (int i = 0; i < temp.length(); i++)
    {
        temp[i]=toLowerCase(temp[i]);
    }

    return checkpalindrome(temp);
    
}
int main()
{
    string s = "A man, a plan, a canal: Panama";
    if(IsValidPalindrome(s)){
        cout<<"valid palindrome";
    }
    else{
        cout<<" no its not";
    }
    return 0;
}