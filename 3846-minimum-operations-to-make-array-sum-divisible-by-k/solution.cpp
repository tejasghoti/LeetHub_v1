
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        if(sum % k == 0){
            cnt = 0;
        }
        else {
            cnt = sum % k;
        }
        return cnt;
    }
};

/*
class Solution {
public:
int minOperations(vector<int>& nums, int k){
    int n= nums.size();
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += nums[i];
    }
    int rem = sum % k;
    return rem;
}
};
*/
