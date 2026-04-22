#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i = 0; i < n; i++) {
        cin>>nums[i];
    }
    int ans=nums[0];
    int prefix=nums[0];
    int suffix=nums[n-1];
    for(int i = 1; i < n ; i++) {
        if(prefix==0)prefix=1;
        if(suffix==0)suffix=1;
        prefix=prefix*nums[i];
        suffix=suffix*nums[n-1-i];      

        ans=max(ans,max(prefix,suffix));
    }
    cout<<ans;
    return 0;
}