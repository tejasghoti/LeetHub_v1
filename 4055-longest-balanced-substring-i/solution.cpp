class Solution {
public:
    int longestBalanced(string s) {
        bool isBal = false;
        int n=s.size();
        int ans = 0;

        for(int i = 0; i<n; i++){
            vector<int> freq(26,0);
            int distinct = 0;
            int maxFreq = 0;
            //if(string[i])
            for(int j = i;j<n;j++){
                int idx = s[j] - 'a';
                if(freq[idx] == 0){
                    distinct++;
                }
                freq[idx]++;
                maxFreq = max(maxFreq,freq[idx]);
                int lenght = j - i+1;
                if (lenght == distinct * maxFreq){
                    ans = max(ans,lenght);
                }
            }
        }
        return ans;
    }
};
