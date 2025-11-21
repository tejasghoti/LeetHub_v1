class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        int cnt = 0;
        int j;
        //int once, twice;
        
        //int m = middle.size();
        for(char c = 'a';c <= 'z'; c++){
            int once = -1;
            int twice = -1;
            for(int i=0; i<n; i++){
            if(s[i] == c){
                once = i;
                //i++;
                break;
            }
            }
            for(int j= n-1; j>=0; j--){
                if(s[j] == c){
                    twice = j;
                    break;
                }
            }
            if(once != -1 && twice != -1 && once < twice){
                unordered_set<char> middle;
                for(int k = once + 1; k < twice; k++){
                    middle.insert(s[k]);
                }
                cnt = cnt + middle.size();
            }
        
        }
        return cnt;
    }
};

/*
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        int cnt = 0;
        
        for (char c = 'a'; c <= 'z'; c++) {
            // Find first and last occurrence using built-in functions
            int first = s.find(c);
            int last = s.rfind(c);
            
            if (first != string::npos && first < last) {
                // Count unique characters between first and last
                unordered_set<char> middle(s.begin() + first + 1, s.begin() + last);
                cnt += middle.size();
            }
        }
        
        return cnt;
    }
};
*/


