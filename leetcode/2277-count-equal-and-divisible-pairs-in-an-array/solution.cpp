class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mp;
        int n = nums.size();
        for( int i = 0 ; i < n ; i++) mp[nums[i]].push_back(i);
        int ans = 0;
        for( auto i : mp){
            for( int j : i.second){
                for( int l : i.second){
                    if( j != l && ((j*l)%k) == 0) ans++;
                }
            }
        }
        return ans/2;
    }
};
