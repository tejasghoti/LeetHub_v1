class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>map;
        int i=0, j =0,cnt =0;
        int ans = INT_MIN;
        int n= fruits.size();
    
        while(j<n){
            map[fruits[j]]++;
            cnt++;
            while( i < n && map.size() > 2){
                map[fruits[i]]--;
                if(map[fruits[i]] == 0)map.erase(fruits[i]);
                i++;
                cnt--;

            }
            ans = max(ans,cnt);
            j++;
        }
        return ans;
    }
};
//doit again -nscrpt
