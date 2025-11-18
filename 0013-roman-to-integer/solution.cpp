class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman={
            {'I',1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int ans = 0;
        int n=s.length();

        for(int i=0; i<n; i++){
            if(i+1 < n && roman[s[i]] < roman[s[i+1]]){//i+1 <n to check if the next index exists...
                ans -= roman[s[i]];
            }else{
                ans += roman[s[i]];
            }
           // ans += roman[s[n-1]];
        }
        return ans;
    }
};
