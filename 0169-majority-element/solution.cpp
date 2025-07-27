class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int n = nums.size();
        for(int num : nums){
            cnt[num]++;
            if(cnt[num] > n/2){
                return num;
            }
        }
        return -1;
    }
};

/*class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};
*/


