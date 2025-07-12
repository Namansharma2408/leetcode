struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        unordered_set<pair<int,int>,pair_hash> s;
        int n = nums.size();
        int ans = 0;
        mp[nums[0]]++;
        for( int i = 1 ; i < n ; i++){
            if(mp[nums[i]+k]){
                s.insert({nums[i],nums[i]+k});
            };
            if(mp[nums[i]-k]){
                s.insert({nums[i]-k,nums[i]});
            };
            mp[nums[i]]++;
        }
        return s.size();
    }
};
