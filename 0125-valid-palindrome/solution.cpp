class Solution {
public:
    bool isPalindrome(string s) {
        regex re("[^a-zA-Z0-9]");
        s = regex_replace(s, re, "");
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        return s == reversed;
    }
};
