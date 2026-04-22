#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int n,m;
void find_LCS(vector<vector<int>>&grid){
     for(int i = 1; i <n; i++) {
         for(int j = 1; j <m; j++) {
             if(s1[i-1]==s2[j-1]){
                grid[i][j]=grid[i-1][j-1]+1;
             }
             else{
                grid[i][j]=max(grid[i-1][j],grid[i][j-1]);
             }
         }
     }
}
int main() {
    cin>>s1>>s2;
    n=s1.size()+1;
    m=s2.size()+1;
    vector<vector<int>>grid(n,vector<int>(m,0));
    find_LCS(grid);
    for(int i = 0; i <n  ; i++) {
        for(int j = 0; j < m; j++) {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}