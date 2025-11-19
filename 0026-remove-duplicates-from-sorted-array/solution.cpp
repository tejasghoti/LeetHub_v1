class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int n=nums.size();
        //2pointer approach
        for(int j=0; j<n; j++){
            //if jth element is not equal to ith means its unique
            if(nums[j] != nums[i]){
                i++;
                //so, i++ and nums ith position vr nums[j] as both will be unique
                nums[i] = nums[j];
            }
        }
        //return total uniq. elements
        return i+1;
    }
};
