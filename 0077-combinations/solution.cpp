class Solution {
public:
    void fun(int i,vector<int>&v ,vector<vector<int>>&ans,int k,int n){
        
       if(k == 0){
        ans.push_back(v);
        return ;
       }
       if(i>n)return ;
       
        v.push_back(i);
        fun(i+1,v,ans,k-1,n);
        v.pop_back();
        fun(i+1,v,ans,k,n);
        


     }
    vector<vector<int>> combine(int n, int k) {
        vector<int>v;
        vector<vector<int>>ans;
        fun(1,v,ans,k,n);
        return ans;
    }
};
