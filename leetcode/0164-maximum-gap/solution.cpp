class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if( n < 2 ) return 0;

        int maxGap = 0;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for( int i = 0 ; i < n ; i++ ){
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
        }

        int bucketSize = (maxi - mini + n-2)/(n-1);
        vector<int> minOfBucket(n-1,INT_MAX);
        vector<int> maxOfBucket(n-1,INT_MIN);

        for( int i = 0 ; i < n ; i++ ){
            if( nums[i] == mini || nums[i] == maxi ) continue;
            int bucketIndexForCurrentEl = (nums[i]-mini)/bucketSize;
            minOfBucket[bucketIndexForCurrentEl] = min(minOfBucket[bucketIndexForCurrentEl],nums[i]);
            maxOfBucket[bucketIndexForCurrentEl] = max(maxOfBucket[bucketIndexForCurrentEl],nums[i]);
        }

        for( int i = 0 ; i < n-1 ; i++ ){
            if( maxOfBucket[i] == INT_MIN) continue;


            maxGap = max(minOfBucket[i] - mini,maxGap);
            mini = maxOfBucket[i];
        }
        maxGap = max(maxGap,maxi-mini);
        return maxGap;

    }
};
