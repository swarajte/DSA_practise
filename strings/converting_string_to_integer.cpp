#include <bits/stdc++.h>
using namespace std;


int myAtoi(string s) {
        int i=0,len=s.length(),sign=1;
        if(len==0){
            return 0;
        }

        while(i<len && s[i]==' '){
            i++;            // going beyond white spaces if any
        }

        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+'){
            i++;
            
        }
        long int out=0;
            while(s[i]>='0' && s[i]<='9'){
                out=out*10;
                if(out<=INT_MIN || out>=INT_MAX){
                    break;
                }
                out+=s[i]-'0';
                i++;
            }

            if(sign==-1){
                out=(sign)*out;
            }
            if(out<=INT_MIN){
                return INT_MIN;
            }
            if(out>=INT_MAX){
                return INT_MAX;
            }
            return int(out);

        }

int main()
{
    string s = "  -888";
    cout<<myAtoi(s);
    
    return 0;
}