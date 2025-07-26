#include <unordered_set>
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> check;
        while (n != 1 && check.count(n) == 0) {
            check.insert(n);
            int sum = 0, temp = n;
            while (temp > 0) {
                int x = temp % 10;
                sum += x * x;
                temp /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};

