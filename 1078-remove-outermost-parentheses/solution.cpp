class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans;
        //int n = s.lenghth();
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                if(!st.empty()){
                    ans += s[i];
                }
                st.push(s[i]);
            } else if(s[i] == ')'){
                st.pop();
                if(!st.empty()) ans += s[i];
            }
        }
        return ans;
    }
};
// Stack tracks nesting depth: empty=outermost level, not empty=inside boxes
// For '(': add only if stack not empty (already inside), then push to go deeper
// For ')': pop to exit current box, add only if stack not empty after pop (still inside other boxes)
