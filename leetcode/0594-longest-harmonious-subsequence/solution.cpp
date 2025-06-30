class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        for( int i = 0 ; i < n ; i++){
            mp[nums[i]]++;
        }
        int maxi = 0;
        for (auto it = mp.begin(); next(it) != mp.end(); ++it) {
            auto nextIt = next(it);
            if(((nextIt->first)-(it->first)) == 1)maxi = max(maxi,((nextIt->second)+(it->second)));
        }
        return maxi;
    }
};
