/*class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int even = 0;
        int odd = 0;
        int n = nums.size();
        bool isBalanced = false;
        int maxLen = 0;

        for(int i=0; i<n; i++){
            if(nums[i] % 2 == 0){
                even++;
            }
            else if(nums[i]%2 == 1){
                odd++;
            }

        }
        if(odd == even){
            isBalanced = true;

        }
        return n;

    }
};
*/
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        for(int i = 0; i < n; i++) {
            unordered_set<int> even;
            unordered_set<int> odd;
            
            for(int j = i; j < n; j++) {
                if(nums[j] % 2 == 0) {
                    even.insert(nums[j]);
                } else {
                    odd.insert(nums[j]);
                }
                if(even.size() == odd.size()) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};

