class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) {
            return res;
        }
        vector<string> mapping = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        res.push_back("");
        for (char digit : digits) {
            vector<string> temp;
            int idx = digit - '0';
            for (char ch : mapping[idx]) {
                for (string s : res) {
                    temp.push_back(s + ch);
                }
            }
            res.swap(temp);
        }
        return res;
    }
};

