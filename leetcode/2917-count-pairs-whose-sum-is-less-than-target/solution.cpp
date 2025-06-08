class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int ans = 0, n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        int lo = i + 1, hi = n - 1, res = i;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[i] + nums[mid] < target) {
                res = mid; // track the last index satisfying the condition
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        // count of pairs for index i is (res - i)
        ans += (res - i);
    }
    return ans;
}

};
