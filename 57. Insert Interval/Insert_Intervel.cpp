#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<vector<int>>intervals(n,vector<int>(2));
    vector<int>newInterval(2);
    int a,b;
    for(int i = 0; i < n; i++) {
            cin>>a>>b;
            intervals[i][0]=a;
            intervals[i][1]=b;
    
    }
    cin>>a>>b;
    newInterval[0]=a;
    newInterval[1]=b;

    int satrt=-1,end=-1;
    bool check=false;
    vector<vector<int>>ans;
    for(int i = 0; i <n; i++) {

            if(intervals[i][0]<=newInterval[0] && newInterval[0]<=intervals[i][0]){
                satrt=intervals[i][0];
                end=newInterval[1];
            }
            else if(intervals[i][1]>=newInterval[1] && intervals[i][0]<=newInterval[1]){
                end=intervals[i][1];
                break;
            }

    }
    cout<<satrt<<" "<<end<<endl;
    for(int i = 0; i < n; i++) {
        if(intervals[i][0]>=satrt && intervals[i][1]<=end){
            if(!check){
                ans.push_back({satrt,end});
                check=true;
            }
        }else ans.push_back({intervals[i][0],intervals[i][1]});
    }
   if(satrt==-1 && end==-1)ans.push_back({newInterval[0],newInterval[1]});
    for(auto c:ans){
        for(int x:c)cout<<x<<" ";
        cout<<'\n';
    }
    cout<<ans.size();
    return 0;
}