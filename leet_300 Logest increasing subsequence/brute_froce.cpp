#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int>nums(n);
    vector<int>track(n,1);
    int mx=1;
    for(int i=0;i<n;i++) cin>>nums[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[j]<nums[i] && track[j]+1>track[i])
            track[i]=track[j]+1;
        }
    mx=max(mx,track[i]);
    }
    cout<<mx;
    return 0;
}