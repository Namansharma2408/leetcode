class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> rums(n+1,0);
        int m = queries.size();
        for( int i = 0 ; i < m ; i++){
            rums[queries[i][0]]--;
            rums[queries[i][1]+1]++;
        }
        for( int i = 1 ; i < n ; i++) rums[i] += rums[i-1];
        for( int i = 0 ; i < n ; i++) if( nums[i] + rums[i] > 0) return false;
        return true;
    
    }
};
