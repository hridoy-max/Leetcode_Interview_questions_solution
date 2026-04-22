#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<bool>>visited_pacific;
vector<vector<bool>>visited_atlantic;
vector<vector<int>>grid;
vector<vector<int>>answer;
bool check_pasific=true;
vector<pair<int,int>>go_to={{-1, 0},{1, 0},{0, -1},{0, 1}};
bool isValid(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);
}

void find_water_flow(int dc,int dr){

    if(check_pasific)visited_pacific[dc][dr]=true;
    else visited_atlantic[dc][dr]=true;
    
    for(int i = 0; i < 4; i++) {
        int sc=dc+go_to[i].first;
        int sr=dr+go_to[i].second;
        if(isValid(sc,sr) && grid[sc][sr]>=grid[dc][dr]){
            if(check_pasific && !visited_pacific[sc][sr]){
            find_water_flow(sc,sr);}
            else if(!check_pasific && !visited_atlantic[sc][sr])
               find_water_flow(sc,sr);}
            }
        }

int main() {
    cin>>n>>m;
    grid.resize(n,vector<int>(m));
    visited_atlantic.resize(n,vector<bool>(m,false));
    visited_pacific.resize(n,vector<bool>(m,false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>grid[i][j];
        }
    }
    //pacific
    for(int i = 0; i < m; i++) {
        find_water_flow(0,i);
    }
    for(int i = 1; i < n; i++) {
        find_water_flow(i,0);
    }

    //atlantic
    check_pasific=false;
    for(int i = 0; i < m; i++) {
        find_water_flow(i,m-1);
    }
    for(int i = 0; i < n-1; i++) {
        find_water_flow(n-1,i);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
           if(visited_atlantic[i][j] && visited_pacific[i][j])
           answer.push_back({i,j});
        }
    }
    for(auto c:answer){
        for(int x:c)cout<<x<<" ";
        cout<<'\n';
    }
    return 0;
}