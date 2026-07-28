class Solution {
public:
    int numberOfSpecialChars(string word) {
        int special = 0;

        vector<bool> lower(26, false);
        vector<bool> upper(26, false);
        for (char ch : word) {
            if (islower(ch))
                lower[ch - 'a'] = true;
            else
                upper[ch - 'A'] = true;
        }
        for (int i = 0; i < 26; i++) {
            if (lower[i] && upper[i]) {
                special++;
            }
        }

        return special;
    }
};