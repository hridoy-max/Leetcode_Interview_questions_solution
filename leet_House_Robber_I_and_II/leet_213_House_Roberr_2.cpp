#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();    

    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);

    vector<int> total_loot(n, 0);
    int max_loot = INT_MIN;
    
    // case-1: first house include, last exclude
    total_loot[0] = nums[0];
    total_loot[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n - 1; i++) {
        total_loot[i] = max(total_loot[i-2] + nums[i], total_loot[i-1]);
    }

    max_loot = total_loot[n-2];
    
    // case-2: first house exclude, last include
    fill(total_loot.begin(), total_loot.end(), 0);

    total_loot[1] = nums[1];
    total_loot[2] = max(nums[1], nums[2]);

    for (int i = 3; i < n; i++) {
        total_loot[i] = max(total_loot[i-2] + nums[i], total_loot[i-1]);
    }

    max_loot = max(max_loot, total_loot[n-1]);

    return max_loot;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << rob(nums) << endl;

    return 0;
}