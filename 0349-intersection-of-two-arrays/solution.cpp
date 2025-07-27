#include <vector>
#include <unordered_set>

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set(nums1.begin(), nums1.end());
        vector<int> ans;
        for (size_t id= 0; id < nums2.size(); id++) {
            int num = nums2[id];
            if (set.erase(num)) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};

