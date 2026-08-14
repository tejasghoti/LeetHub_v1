class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int ans = 0;

        for(int l = 0; l < n; l++) {
            array<int, 26> count{};
            for(int r = l; r < n; r++) {
                int idx = s[r] - 'a';
                count[idx]++;
                if(count[idx] > 2) {
                    break;
                }
                ans = max(ans, r - l + 1);
            }
        }
        return ans;
    } 
};