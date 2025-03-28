class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for( int i : nums) mp[i]++;
        vector<int> ans;
        int n = nums.size();
        for( auto i : mp) if(i.second > n/3) ans.push_back(i.first);
        return ans;
    }
};
