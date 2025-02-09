class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        for( int i = 0 ; i < n ; i++) nums[i] -= i;
        unordered_map<int,int> badCount;
        for( int i = 0 ; i < n ; i++) badCount[nums[i]]++;
        long long count = 0;
        for( auto i : badCount) count += (i.second)*(n-i.second);
        return count/2;
    }
};
