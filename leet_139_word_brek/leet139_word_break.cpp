#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<string>wordDict(n);
    unordered_set<string>st;
    int max_len=0;
    for(int i = 0; i < n; i++) {
        cin>>wordDict[i];
        st.insert(wordDict[i]);
        max_len=max((int)wordDict[i].length(),max_len);
    }
    vector<bool>trakc((int)s.length()+1,false);
    trakc[0]=true;
    for(int i = 1; i < s.length()+1; i++) {
        for(int j = i-1; j >=max(0,i-max_len) ; j--) {
            if(trakc[j] && st.count(s.substr(j,i-j))){
                trakc[i]=true;
                break;
            }
        }
    }
    if(trakc[s.length()])cout<<"true";
    else cout<<"false";
    return 0;
}