class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = happiness.size();
        int turns = 0;
        long long totalHappiness = 0;
        //sorting in descending order --> greater<int>()
        sort(happiness.begin(), happiness.end(),greater<int>());
        for(int i = 0; i<k; i++){
            //ensures it does'nt go negative
            totalHappiness = totalHappiness + max(happiness[i] - turns,0);
            turns++;
        }
        return totalHappiness;
    }
};
//TotalHappiness = happiness + happiness[maxH] ;
        //maxH = max(maxH, happiness[k]);
        //happiness >= 0;
        //happiness[i] - 1;
