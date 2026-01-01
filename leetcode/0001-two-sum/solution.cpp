class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v = nums;
        sort(v.begin(),v.end());
        int i = 0;
        int j = v.size() - 1;
        while( i < j ){
            int x = v[i] + v[j];
            if( x == target ) break;
            else if( x > target ) j--;
            else i++;
        }
        vector<int> ans;
        for( int k = 0 ; k < nums.size() ; k++ ){
            if( nums[k] == v[i] || nums[k] == v[j] ){
                ans.push_back(k);
            }
        }
        if( ans[0] > ans[1] ) swap(ans[0],ans[1]);
        return ans;
    }
};
