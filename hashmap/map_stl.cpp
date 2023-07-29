#include <bits/stdc++.h> 
using namespace std;

int main()
{

    unordered_map<string,int> mp;
    mp["swaraj"]=1;
    pair<string,int> p=make_pair("telkhade",2);
    mp.insert(p);

    cout<<mp["swaraj"]<<" "<<mp["telkhade"]; 

    mp["is"]=3;
    mp["jjj"]=7;

    // entry is formed with 0 whenever we write mp[""]
    cout<<" "<<mp["unknown"]<<endl;  

    //gives isze of map
    cout<<"size of map "<<mp.size()<<endl;   

    // just like count gives value for given key 
    cout<<"count function will give its value if not present 0 "<<mp.count("l")<<endl; 

    //erases from map
    mp.erase("is");
    cout<<mp.count("is")<<endl; 


    cout<<"by for loop"<<endl;
    for(auto i:mp){
        cout<<i.first<<" : "<<i.second<<endl;
    }

    cout<<"by iterator "<<endl;
    unordered_map<string,int> :: iterator it=mp.begin();
    while(it!=mp.end()){
        cout<<it->first<<" : "<<it->second<<endl;
        it++;
    }
    return 0;
}