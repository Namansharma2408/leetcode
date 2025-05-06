class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n = nums.size();
        for( int i = 0 ; i < n ; i++) pq.push(nums[i]);
        for( int i = 0 ; i < k ; i++){
            int k = pq.top();
            pq.pop();
            k = -k;
            pq.push(k);
        }
        int ans = 0;
        for( int i = 0 ; i < n ; i++) ans += pq.top(),pq.pop();
        return ans;

    }
};
