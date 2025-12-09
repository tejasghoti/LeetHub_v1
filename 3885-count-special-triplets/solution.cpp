class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        long long result = 0;
        
        // Count frequency of each element from index j+1 onwards
        unordered_map<int, int> rightFreq;
        for (int k = 2; k < n; k++) {
            rightFreq[nums[k]]++;
        }
        
        // Count frequency of elements before j
        unordered_map<int, int> leftFreq;
        
        // Iterate through possible j values
        for (int j = 1; j < n - 1; j++) {
            // Add nums[j-1] to left frequency
            if (j > 1) {
                leftFreq[nums[j - 1]]++;
            } else {
                leftFreq[nums[0]]++;
            }
            
            int target = nums[j] * 2;
            
            // Count valid triplets with this j
            long long leftCount = leftFreq[target];
            long long rightCount = rightFreq[target];
            
            result = (result + (leftCount * rightCount) % MOD) % MOD;
            
            // Remove nums[j+1] from right frequency for next iteration
            if (j + 1 < n) {
                rightFreq[nums[j + 1]]--;
                if (rightFreq[nums[j + 1]] == 0) {
                    rightFreq.erase(nums[j + 1]);
                }
            }
        }
        
        return result;
    }
};
