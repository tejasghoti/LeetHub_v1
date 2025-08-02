class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int l = 0;
        int maxlen = 1;

        for (int right = 0; right < n; right++) {
    while (l <= right && (long long)nums[right] > (long long)nums[l] * k) {
                l++;
            }
            maxlen = max(maxlen, right - l + 1);
        }
        return n - maxlen;
    }
};


/*
            bool isBalanced(){
            if(nums[n] <= nums[i]){
                true;
            }else false;
        }
        for(int i=0; i<n; i++){
            if(nums != isBalanced){
                nums.pop_back();
                int new;
            }
        }
        */
