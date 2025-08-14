#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        string maxi = "";
        for (size_t i = 0; i + 2 < num.size(); ++i) {
            if (num[i] == num[i+1] && num[i+1] == num[i+2]) {
                maxi = max(maxi, num.substr(i, 3));
            }
        }
        return maxi; 
    }
};

