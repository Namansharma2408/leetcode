class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for( int i = 0 ; i <= k && i < n ; i++) mp[nums[i]]++;
        for( auto i : mp ) if( i.second >= 2) return true;
        for( int i = k + 1 ; i < n ; i++){
            mp[nums[i-k-1]]--;
            mp[nums[i]]++;
            if( mp[nums[i]] >= 2 ) return true;
        }
        return false;
    }
};
