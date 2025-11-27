/*
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxS = LLONG_MIN;
          for(int len = k; len <= n; len += k) {
             long long currS = 0;
            for(int i = 0; i < len; i++) {
                currS += nums[i];
            }
            maxS = max(maxS, currS);
            // Sliding window to find max sum for all subarrays of this length
            for(int i = len; i < n; i++) {
                currS = currS - nums[i - len] + nums[i];
                maxS = max(maxS, currS);
            }
        }
        return maxS;
    }
};
*/

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long prefixSum = 0, maxSum = LONG_LONG_MIN;
        vector<long long> kSum(k, LONG_LONG_MAX / 2);
        kSum[k - 1] = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            maxSum = max(maxSum, prefixSum - kSum[i % k]);
            kSum[i % k] = min(kSum[i % k], prefixSum);
        }
        return maxSum;
    }
};

