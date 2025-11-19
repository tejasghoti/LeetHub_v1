class Solution {
public:
    int removeElement(vector<int>& a, int val) {
        int i = 0;
        int n= a.size();
        for (int j = 0; j < n; j++) {
            if (a[j] != val) {
                a[i] = a[j];
                i++;
            }
        }
        return i;
    }
};

