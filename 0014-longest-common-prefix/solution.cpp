class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(strs.empty()){
            return "";
        }

        for (int i=0; i<strs[0].length(); i++){
            char ans = strs[0][i];
            for(int j=1; j<n; j++){
                if(i == strs[j].length() || strs[j][i] != ans){
                    return strs[0].substr(0,i);
                }
                //j ran out of character or template(ans) does'nt matches
            }
        }
        return strs[0];
    }
};
