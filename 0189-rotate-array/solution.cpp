class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;//to handle k > n
        //shevtun ele. rotate karun pudhe aanar
        Reverse(nums,0, n-1);
        Reverse(nums,0, k-1);
        Reverse(nums,k, n-1);
    }

    void Reverse(vector<int>& nums, int l, int r){
        while(l<r){
            swap(nums[l],nums[r]);
            l++;
            r--;
        }
    }
};
