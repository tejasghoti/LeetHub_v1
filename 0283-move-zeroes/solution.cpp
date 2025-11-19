class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0; //pos =>int j=0
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                //swap(nums[i], nums[pos]);
                int temp = nums[i];
                nums[i] = nums[pos];
                nums[pos] = temp;
                pos ++; //j++
            }
        }
    }
};
