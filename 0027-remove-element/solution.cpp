class Solution {
public:
    int removeElement(vector<int>& a, int v) {
        int i = 0;
        for (int j = 0; j < a.size(); j++) {
            if (a[j] != v) {
                a[i] = a[j];
                i++;
            }
        }
        return i;
    }
};

