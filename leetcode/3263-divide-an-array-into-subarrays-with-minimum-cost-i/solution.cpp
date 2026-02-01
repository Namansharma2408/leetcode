class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(2);
        v[0] = nums[1];
        v[1] = nums[2];
        if( v[0] > v[1] ){
            swap(v[0],v[1]);
        }
        for( int i = 3 ; i < n ; i++ ){
            if( nums[i] < v[0] ){
                v[1] = v[0];
                v[0] = nums[i];
            } else if( nums[i] < v[1] ){
                v[1] = nums[i];
            }
        }
        return (nums[0]+v[0]+v[1]);
    }
};
