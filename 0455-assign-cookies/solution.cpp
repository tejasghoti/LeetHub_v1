class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
        int j = 0;
        int glen = g.size();
        int slen = s.size();
        while (i < glen && j < slen) {
            if (g[i] <= s[j]) {
                i++;
            }
            j++;
        }
        return i;
    }
};

