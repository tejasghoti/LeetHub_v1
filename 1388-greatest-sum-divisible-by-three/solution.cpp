/*
class Solution{
public:
    int maxSumDivThree(vector<int> & nums){
        vector<int> r1, r2; //remainders of 1 and 2 resp.
        int sum = 0;

        for(int n: nums){
            sum += n;
            if(n % 3 == 1){
                r1.push_back(n);
            }else if (n % 3 == 2){
                r2.push_back(n);
            }
        }
         sort(r1.begin(), r1.end());
         sort(r2.begin(), r2.end());
        int r = sum % 3;
        if(r == 0){
            return sum;
        }else if(r == 1){
            int res = 0;
            if(!r1.empty()){
                res = max(res, sum - r1[0]);
            }
            if(r2.size() >= 2){
                res = max(res, sum - r2[0] - r2[1]);
            }
            return res;
        }else{  // r == 2
            int res = 0;
            if(!r2.empty()){
                res = max(res, sum - r2[0]);
            }
            if(r1.size() >= 2){
                res = max(res, sum - r1[0] - r1[1]);
            }
            return res;
        }
    }
};
*/
class Solution {
    int n;
    vector<vector<int>> dp;
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        int dp[n + 1][3];
        dp[0][0] = 1; dp[0][1] = dp[0][2] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int m = 0; m < 3; ++m) {
                int skip = dp[i - 1][m], pick = 0, x = dp[i - 1][(m + nums[i - 1]) % 3];
                if (x) pick = nums[i - 1] + x;
                dp[i][m] = max(pick, skip);
            }
        }
        return dp[n][0] - 1;
    }
};
