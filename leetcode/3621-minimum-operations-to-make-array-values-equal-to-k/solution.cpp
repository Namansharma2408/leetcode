class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<int,int> mp;
        int n = nums.size();
        for( int i = 0 ; i < n ; i++) mp[nums[i]]++;
        int ans = 0;
        while( mp.size() >= 2){
            int a = (prev(mp.end()))->first;
            int b = mp[a];
            mp.erase((prev(mp.end())));
            int c = (prev(mp.end()))->first;
            int d = mp[c];            
            if( a <= k || c < k ) return -1 ;
            ans++;
        }
        int a = (prev(mp.end()))->first;
        int b = mp[a];  
        if( k < a) ans++;
        else if( k > a) return -1;
        return ans;
    }
};
