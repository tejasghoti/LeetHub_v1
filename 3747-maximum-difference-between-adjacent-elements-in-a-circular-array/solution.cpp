#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        vector<int> differences;
        for (int i = 0; i < n; i++) {
            int diff = abs(nums[i] - nums[(i + 1) % n]);
            differences.push_back(diff);
        }
        sort(differences.begin(), differences.end());
        return differences.back();
    }
};

