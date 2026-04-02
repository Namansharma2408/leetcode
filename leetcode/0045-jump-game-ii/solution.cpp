class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n,INT_MAX);
        v[0] = 0;
        for( int i = 0 ; i < n ; i++ ){
            for( int j = nums[i] ; j > 0 ; j-- ){
                if( (i + j) >= n ) continue;
                v[i+j] = min(v[i+j], 1+v[i]);
            }
        }
        return v[n-1];
    }
};
