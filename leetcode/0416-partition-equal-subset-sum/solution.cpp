class Solution {
public:
    bool canPartition(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        int sum = 0;
        for( int i = 0 ; i < n ; i++) sum += nums[i];
        if( sum%2 == 1) return false;
        s.insert(nums[0]);
        s.insert(0);
        for( int i = 1 ; i < n ; i++){
            unordered_set<int> temp;
            for( int j : s) {
                int k = j + nums[i];
                if( k == sum/2) return true;
                if( k < sum/2 )temp.insert(k);
            }
            s.insert(temp.begin(),temp.end());
        }
        if( s.find(sum/2) != s.end()) return true;
        return false;

    }
};
