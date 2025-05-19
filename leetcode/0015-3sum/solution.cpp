class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if( nums[0] > 0 || nums[n-1] < 0) return {};
        set<vector<int>> result;
        for( int i = 0 ; i < n-2 ; i++){
            if( nums[i] > 0 ) break;
            if( i != 0 && nums[i] == nums[i-1]) continue;
            int j = i+1,k = n-1;
            while( j < k){
                int sum = nums[i]+nums[j]+nums[k];
                if( sum > 0) k--;
                else if( sum < 0) j++;
                else {
                    result.insert({nums[i],nums[j],nums[k]});
                    j++,k--;
                }
            }
        }
        vector<vector<int>> ans(result.begin(),result.end());
        return ans;
    }
};
