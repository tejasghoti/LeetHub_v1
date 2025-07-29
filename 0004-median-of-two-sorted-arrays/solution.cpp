class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;

        int idx1 = (total - 1) / 2;
        int idx2 = total / 2;

        int i = 0, j = 0, ct = 0;
        int val1 = 0, val2 = 0;

        while (ct <= idx2) {
            int val;
            if (i < m && (j >= n || nums1[i] <= nums2[j])) {
                val = nums1[i++];
            } else {
                val = nums2[j++];
            }

            if (ct == idx1) val1 = val;
            if (ct == idx2) val2 = val;

            ct++;
        }

        if (total % 2 == 0)
            return (val1 + val2) / 2.0;
        else
            return val2;
    }
};

