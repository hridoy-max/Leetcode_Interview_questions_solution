#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i = 0; i < n; i++)cin>>nums[i];

    vector<int>max_sub;
    max_sub.push_back(nums[0]);
    for (int i = 1; i < n; i++)
    {
        if(nums[i]>max_sub.back())max_sub.push_back(nums[i]);
        else{
            auto it=lower_bound(max_sub.begin(),max_sub.end(),nums[i]);
            *it=nums[i];
        }
    }
    cout<<max_sub.size();
    return 0;
}