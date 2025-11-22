/*class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int curr = 0;
        int cnt = 0;

        for(int i=0; i<n; i++){
            if(nums[i] % 3 == 0){
                continue;
            }
            else if(nums[i] % 3 == 1){
                nums[i] = nums[i] - 1;
                cnt ++;
                continue;
            }
            else if(nums[i] % 3 == 2){
                nums[i] = nums[i] + 1;
                cnt ++;
                continue;
            }
        }
        return cnt;
    }
};
*/
class Solution {
    public:
    int minimumOperations(vector<int> & nums){
        //int n = nums.size();
        int cnt = 0;
        for( int n : nums ){
            if(n % 3 != 0){
                cnt ++;
            }
        }
        return cnt;
    }
};
