class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int a = landStartTime.size();
        int b = waterStartTime.size();
        int mini = INT_MAX;
        for(int i=0; i<a; i++){
            for(int j=0; j<b; j++){
                int lTotal = landStartTime[i] + landDuration[i];
                int wBegin = max(lTotal, waterStartTime[j]);
                int wEnd = wBegin + waterDuration[j];
                mini = min(mini, wEnd);


                int water1=waterStartTime[j]+waterDuration[j];
                int land2Begin=max(water1, landStartTime[i]);
                int land2End=land2Begin+landDuration[i];
                mini = min(mini, land2End);


                
            }
            
        }
        return mini;
    }
};