class Solution {
public:
    long long removeZeros(long long n) {
        string ans= " ";
        string s = to_string(n);

        for(char c: s){
            if( c != '0'){
                ans = ans + c;//we will add ans + the char c if its not '0'
            }
        }
        return stoll(ans);
      
    }
};
