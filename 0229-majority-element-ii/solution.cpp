class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        sort(nums.begin(), nums.end());
        int count = 1;
        for(int i = 0; i < n; i++){
            if(i < n - 1 && nums[i] == nums[i + 1]){
                count++;
            }
            else {
                if(count > n / 3){
                    result.push_back(nums[i]);
                }
                count = 1; 
            }
        }
        return result;
    }
};
