class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int noz = 0;
        int noo = 0;
        int n = nums.size();
        for( int i = 0 ; i < n ; i++ ){
            if( nums[i] == 0 ) noz++;
        }
        noo = n-noz;
        int nozbefore = 0;
        for( int i = 0 ; i < n ; i++ ){
            int x = nozbefore + noo;
            if( nums[i] == 0 ) nozbefore++;
            else noo--;
            nums[i] = x;
        }
        nums.push_back(nozbefore + noo);
        vector<int> ans;
        int maxi = 0;
        for( int i = 0 ; i < nums.size() ; i++ ){
            maxi = max(maxi,nums[i]);
        }
        for( int i = 0 ; i < nums.size() ; i++ ){
            if(nums[i] == maxi)ans.push_back(i);
        }
        return ans;
    }
};
