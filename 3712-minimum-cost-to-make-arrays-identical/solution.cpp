class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        int n = arr.size();
        long long cost1 = 0;
        for(int i=0;i<n;i++){
            cost1+=abs(arr[i]-brr[i]);
            
        }
        if(n>1){
            sort(arr.begin(),arr.end());
            sort(brr.begin(), brr.end());
            long long cost2 = 0;
            for(int i=0;i<n;i++){
            cost2+=abs(arr[i]-brr[i]);
                
            
        }
            cost2+=k;
            return min(cost1, cost2);
        }
        return cost1;
    }
};
