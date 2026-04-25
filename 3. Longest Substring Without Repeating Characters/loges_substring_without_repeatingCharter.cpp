#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_map<char,int> mp;

    int l = 0, ans = 0;

    for(int r = 0; r < s.length(); r++) {

        if(mp.count(s[r])) {
            l = max(l, mp[s[r]] + 1);
        }

        mp[s[r]] = r;

        ans = max(ans, r - l + 1);
    }

    cout << ans;
}