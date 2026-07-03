class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) 
        return true;  

        long l = 1, high = num / 2; 
        while (l <= high) {
            long mid = l + (high - l) / 2;
            
            long sq = mid * mid;

            if (sq == num) {
                return true;

            } else if (sq < num) {
                l = mid + 1;


            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};
