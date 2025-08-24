class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //string ans= 0;
        if(strs.empty()) {
            return "";
        }
        //for(int i; i < string.length(); i++){

        //}
        for (int i = 0; i < strs[0].length(); i++) {
            char ans = strs[0][i];

            for (int j = 1; j < strs.size(); j++) {
                if (i == strs[j].length() || strs[j][i] != ans) {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0];
    }

    
};
