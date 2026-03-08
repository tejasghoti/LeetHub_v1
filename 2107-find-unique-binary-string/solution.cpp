class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> inte;
        for(string num : nums) {
            inte.insert(stoi(num, 0, 2));
        }
        int n = nums.size();
        for(int num = 0; num<=n; num++){
            if(inte.find(num) == inte.end()) {
                string ans = bitset<16>(num).to_string();
                return ans.substr(16 - n);
            }
        }
        return "";
    }
};
