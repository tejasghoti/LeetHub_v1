class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.length();
        int n = needle.length();

        if(n == 0) return 0;
        if(n > h) return -1;
        
        vector<int> lps(n, 0);
        for(int i = 1; i < n; i++){
            int j = lps[i - 1];
            while(j > 0 && needle[i] != needle[j]){
                j = lps[j - 1];
            }
            if(needle[i] == needle[j]){
                j++;
            }
            lps[i] = j;
        }
        
        int j = 0;
        for(int i = 0; i < h; i++){
            while(j > 0 && haystack[i] != needle[j]){
                j = lps[j - 1];
            }
            if(haystack[i] == needle[j]){
                j++;
            }
            if(j == n){
                return i - n + 1;
            }
        }
        
        return -1;
    }
};
/*
LPS ->
Imagine a word where the beginning and end have matching patterns:
Word: "ABABAB"

Prefixes (from start):  "A", "AB", "ABA", "ABAB", "ABABA"
Suffixes (from end):    "B", "AB", "BAB", "ABAB", "BABAB"

Common ones: "AB" and "ABAB"
Longest: "ABAB" (length 4)
*/
