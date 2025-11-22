/*
class Solution {
public:
    int minimumFlips(int n) {
        string s = "";
        //int temp = n
        while(n>0){
            //converting int to binary
            s = char('0' + (n % 2)) + s;
            n /= 2;   
        }
        int flips = 0;
        int len = s.length();
        for(int i = 0; i< len/2; i++){
            if(s[i] != s[len - i - 1]){
                flips ++;
            }
        }
        return flips;
    }
};
*/
class Solution {
public:
    int minimumFlips(int n) {
        string s = "";
        while (n > 0) {
            //convt. string to binary
            s = char('0' + (n % 2)) + s;
            n /= 2;
        }
        //reversing string s
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        int flips = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != rev[i]) {
                flips++;
            }
        }
        
        return flips;
    }
};

