class Solution {
public:
    int addDigits(int num) {
        int ans;
        if (num==0) return 0;
        //if(num==9) return 9;
        if(num%9==0) return 9;
        for(int i=0; i<num; i++){
            ans = num % 9;
        }
        return ans;
    }
};
