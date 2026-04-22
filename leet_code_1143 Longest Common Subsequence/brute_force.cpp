//Using find out the all sub array

#include<bits/stdc++.h>
using namespace std;
int max_length=0;
string temp="";
void find_out_allSub_string(string &s1,string &s2,int i){
    if(i==s1.length()){
        if(s2.find(temp) != string::npos)max_length=max(max_length,(int)temp.length());
        return;
    }

    //INClude
    temp+=s1[i];
    find_out_allSub_string(s1,s2,i+1);
    
    temp.pop_back();
    //excllude
    find_out_allSub_string(s1,s2,i+1);
}
int main() {
    string s1,s2;
    cin>>s1>>s2;
    
    find_out_allSub_string(s1,s2,0);
    cout<<max_length;
    return 0;
}