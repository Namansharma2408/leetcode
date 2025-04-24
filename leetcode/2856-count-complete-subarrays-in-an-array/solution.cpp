class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for( int i = 0 ; i < n ; i++) mp[nums[i]]++;
        int m = mp.size();
        if( m == 1) return (n*(n+1))/2 ;
        int ans= 0;
        for( int i = 0 ; i < n ; i++){
            unordered_map<int,int> mpp;
            for( int j = i ; j < n ; j++){
                mpp[nums[j]]++;
                if( mpp.size() == m) ans++;
            }
        }
        return ans;
    }
};
