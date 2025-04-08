class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        int y = n%3;
        int idx = n-1;
        unordered_map<int,int> mp;
        int ans;
        n%3 ? ans = n/3+1 : ans = n/3;
        if( y == 1) mp[nums[idx]]++;
        if( y == 2){
            mp[nums[idx]]++;
            mp[nums[--idx]]++;
            if( mp[nums[idx]] == 2) return ans;
        }
        if( y == 0 && n >= 3){
            mp[nums[idx]]++;
            mp[nums[--idx]]++;
            if( mp[nums[idx]] == 2) return ans;
            mp[nums[--idx]]++;
            if( mp[nums[idx]] == 2) return ans;
        }
        idx--;
        ans--;
        for( int i = idx ; i >= 0 ; i -= 3){
            cout<<idx<<endl<<ans<<endl<<endl;
            mp[nums[i]]++;
            if( mp[nums[i]] > 1) return ans;
            mp[nums[i-1]]++;
            if( mp[nums[i-1]] > 1) return ans;
            mp[nums[i-2]]++;
            if( mp[nums[i-2]] > 1) return ans;
            ans--;
        }
        return ans;
    }
};
