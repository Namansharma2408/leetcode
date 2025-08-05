class Solution {
public:
    void dfs(vector<int> &nums,vector<int> &v,int idx,unordered_set<int> &s){
        if(s.find(nums[idx]) != s.end()) return;
        s.insert(nums[idx]);
        v[nums[idx]] = v[idx]+1; 
        dfs(nums,v,nums[idx],s);
    }
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n,0);
        unordered_set<int> s;
        for( int i = 0 ; i < n ; i++){
            if(v[i] == 0 )dfs(nums,v,i,s);
        }
        int maxi = 0;
        for( int i = 0 ; i < n ; i++){
            maxi = max(maxi,v[i]);
        }
        return maxi;
    }
};
