class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        const int NEG = -1e9;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, NEG));

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int prod = nums1[i] * nums2[j];
                dp[i][j] = max({
                    prod,                            // start new subsequence
                    prod + max(0, dp[i + 1][j + 1]), // extend subsequence
                    dp[i + 1][j],                    // skip nums1[i]
                    dp[i][j + 1]                     // skip nums2[j]
                });
            }
        }
        return dp[0][0];
    }
};
