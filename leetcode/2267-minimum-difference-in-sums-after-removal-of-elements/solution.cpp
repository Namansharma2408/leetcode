class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int m = nums.size();
        int n = m/3;
        vector<long long> left(2*n);
        priority_queue<int> pq;
        long long sum = 0;
        for( int i = 0 ; i < 2*n ; i++ ){
            pq.push(nums[i]);
            sum += nums[i];
            if( pq.size() > n ){
                sum -= pq.top();
                pq.pop();
            }
            left[i] = sum;
        }
        // for( int i = 0 ; i < 2*n ; i++ ){
        //     cout<<left[i]<<" ";
        // }
        // cout<<endl;
        vector<long long> right(2*n);
        priority_queue<int,vector<int>,greater<int>> pq2;
        sum = 0;
        for( int i = m-1 ; i >= n ; i-- ){
            pq2.push(nums[i]);
            sum += nums[i];
            if( pq2.size() > n ){
                sum -= pq2.top();
                pq2.pop();
            }
            right[i-n] = sum;
        }
        // for( int i = 0 ; i < 2*n ; i++ ){
        //     cout<<right[i]<<" ";
        // }
        long long ans = LLONG_MAX;
        for( int i = n-1 ; i < 2*n ; i++ ){
            ans = min(ans,left[i]-right[i-n+1]);
        }
        return ans;
    }
};
