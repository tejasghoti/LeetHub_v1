class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0;
        int n = customers.size();
        for(int i=0; i<n; i++){
            if(customers[i] == 'Y'){
                penalty++;
            }
        }
        int minPenalty = penalty;
        int earliestHour = 0;
        for(int i=0; i<n;i++){
            char ch = customers[i];
            if(ch == 'Y'){
                penalty--;
            }else {
                penalty++;
            }
            if(penalty < minPenalty){
                earliestHour = i+1;
                minPenalty = penalty;
            }
        }
        return earliestHour;
    }
};
