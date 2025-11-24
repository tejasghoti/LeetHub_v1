class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int r= 0;
        int n=nums.size();
        vector<bool> ans(n); 
        for(int i = 0; i<n; i++) {
            r = (r*2+nums[i])% 5;
            ans[i] = (r == 0);
        }
        
return ans;
    }
};
