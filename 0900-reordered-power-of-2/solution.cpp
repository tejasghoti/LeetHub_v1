class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string nCount = countDigits(n);

        for (int i = 0; i < 31; ++i) {
            int power = 1 << i;
            if (nCount == countDigits(power))
                return true;
        }
        return false;
    }
private:
    string countDigits(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        return s;
    }
};

