class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total = 0;
        for (int battery : batteries) {
            total += battery;
        }
        
        long long left = 0, right = total / n;
        long long answer = 0;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            
            long long available = 0;
            int computers = n;
            
            for (int battery : batteries) {
                if (battery >= mid) {
                    computers--;
                } else {
                    available += battery;
                }
            }
            
            if (available >= (long long)computers * mid) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return answer;
    }
};
