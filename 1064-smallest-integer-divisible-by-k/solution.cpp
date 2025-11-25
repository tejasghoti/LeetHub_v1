class Solution {
public:
    int smallestRepunitDivByK(int k) {
        //if k is divisible by 2 and 5 then return -1
        if(k % 2 == 0 || k % 5 == 0){
            return -1;
        } //return -1;
        long long rem=0;
        //[1,11,111,1111....]
        for(int len=1; len<= k;len++){
            //if(rem%k ==0) then its divisible by k and return len
            rem = ((rem * 10) +1) % k;
            if(rem == 0){
                return len;
            }
        }
        return -1;
    }
};
