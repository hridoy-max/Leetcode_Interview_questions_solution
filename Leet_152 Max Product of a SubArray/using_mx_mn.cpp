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
    int mx=nums[0];
    int mn=nums[0];
    for(int i = 1; i <n ; i++) {
        if(nums[i]<0)swap(mx,mn);

        mx=max(nums[i],nums[i]*mx);
        mn=min(nums[i],nums[i]*mn);
        
        ans=max(ans,mx);
    }
    cout<<ans;
    return 0;
}
