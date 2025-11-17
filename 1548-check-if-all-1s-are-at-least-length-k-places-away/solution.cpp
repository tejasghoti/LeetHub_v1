class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int latest = -1;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                if(latest != -1 && (i-1-latest) < k){
                    return false;
                    //latest = i;
                }
                latest = i;
            }

        }
        return true;
    }
};
