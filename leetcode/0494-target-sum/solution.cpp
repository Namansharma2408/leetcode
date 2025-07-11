class Solution {
public:
    unordered_map<int, unordered_map<int, int>> dp;

    int sums(vector<int>& nums, int target, int i) {
        if (i == nums.size())
            return target == 0 ? 1 : 0;

        if (dp[i].count(target))
            return dp[i][target];

        int plus = sums(nums, target - nums[i], i + 1);
        int minus = sums(nums, target + nums[i], i + 1);

        return dp[i][target] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        dp.clear();
        ans = sums(nums, target, 0);
        return ans;
    }
};
