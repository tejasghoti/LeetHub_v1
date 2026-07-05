class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max = LLONG_MIN;
        long long secMax = LLONG_MIN; 
        long long thirdMax = LLONG_MIN;
        for(int num : nums){
            long long val = num;
            if(val == max || val ==secMax || val == thirdMax) 
            continue;
            if(val>max){
                thirdMax=secMax;
                secMax=max;
                max=val;
            }else if(val > secMax){
                thirdMax=secMax;
                secMax=val;
            }else if(val>thirdMax){
                thirdMax = val;
            }
        }
         if (thirdMax == LLONG_MIN) {
             return max;
        } else {
            return thirdMax;
}
    }
};
