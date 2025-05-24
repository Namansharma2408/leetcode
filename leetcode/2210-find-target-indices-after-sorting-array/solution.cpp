class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less = 0;
        int equal = 0;
        int n = nums.size();
        for( int i = 0 ; i < n ; i++){
            if( nums[i] < target) less++;
            else if( nums[i] == target) equal++;
        }
        vector<int> v(equal);
        for( int i = 0 ; i < equal ; i++){
            v[i] = less+i;
        }
        return v;



    }
};
