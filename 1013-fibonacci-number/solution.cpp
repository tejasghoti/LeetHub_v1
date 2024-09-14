class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        int last = 1;
        int sec_last = 0;
        for (int i = 2; i <= n; i++) {
            int temp = last;
            last += sec_last;
            sec_last = temp;
        }
        return last;
    }
};
