class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
vector <int> res(nums.size());
        int i = 0;
        for(int n: nums){
            res[i++] = n == 2 ? -1 : (n^(((~n) & (n+1))>> 1));
        }
        return res;
    }
};
