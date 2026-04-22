#include<bits/stdc++.h>
using namespace std;
unordered_set<int>st;
int cunt=1;
int max_length=0;
void find_length(vector<int> &nums,int i){
    while (st.count(i+1))
    {
        cunt++,i++;
    }
    max_length=max(cunt,max_length);
}
int main() {
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i = 0; i < n; i++){cin>>nums[i];
    st.insert(nums[i]);
    }
    unordered_set<int>duplicates;
    for(int i = 0; i < n; i++) {
        if(!st.count(nums[i]-1) && !duplicates.count(nums[i])){
            duplicates.insert(nums[i]);
            find_length(nums,nums[i]);
            cunt=1;
        }
    }  
    cout<<max_length;
    return 0;
}