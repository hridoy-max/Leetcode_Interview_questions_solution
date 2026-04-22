#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i = 0; i < n; i++)cin>>nums[i];
    vector<int>total_loot(n,0);
    int max_loot=INT_MIN;
    
    //case-1
    total_loot[0]=nums[0];
    total_loot[1]=max(nums[0],nums[1]);
    for(int i = 2; i <n-1 ; i++) {
        total_loot[i]=max(total_loot[i-2]+nums[i],total_loot[i-1]);
    }
    max_loot=total_loot[n-2];
    
    //case-2
    fill(total_loot.begin(), total_loot.end(), 0);
    total_loot[1]=nums[1];
    total_loot[2]=max(nums[1],nums[2]);
    for(int i = 3; i <n ; i++) {
        total_loot[i]=max(total_loot[i-2]+nums[i],total_loot[i-1]);
    }
    max_loot=max(max_loot,total_loot[n-1]);

    cout<<max_loot;
    return 0;
}