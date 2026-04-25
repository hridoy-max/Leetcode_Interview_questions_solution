#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<char>>board;
vector<vector<bool>>visited;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}
bool search(string &s,string &word,int j,int k,int p){
     if(word==s)return true;
     for(int i = 0; i < 4; i++) {
         int sr=dx[i]+j;
         int sc=dy[i]+k;
         if(isValid(sr,sc) && !visited[sr][sc] && board[sr][sc]==s[p]){
            word+=s[p];
            visited[sr][sc]=true;
            if(search(s,word,sr,sc,p+1))return true;
         }
     }
     word.pop_back();
     visited[j][k]=false;
     return false;
}
int main() {
    cin>>n>>m;
    board.resize(n,vector<char>(m));
    visited.resize(n,vector<bool>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>board[i][j];
        }
    }
    string s;
    cin>>s;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j]==s[0]){
            visited[i][j]=true;
            string wrod="";
            wrod+=s[0];
            if(search(s,wrod,i,j,1)){
                cout<<"found";
                return 0;
            }
            visited[i][j]=false;
           }
        }
    }
    cout<<"Not fround";
    return 0;
}