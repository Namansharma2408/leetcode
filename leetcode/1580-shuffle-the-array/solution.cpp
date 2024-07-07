class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> v(2*n,0);
        for( int i = 0 ; i < 2*n ; i +=2){
            v[i] = (nums[i/2]);
            v[i + 1] = (nums[i/2 + n ]);
        }
        return v;
    }
};
