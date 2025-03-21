class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        for( int i = 0 ; i < n ; i++) {
            arr[i] %= k;
            if( arr[i] < 0) arr[i] += k;
        }
        unordered_map<int,int> mp;
        for( int i = 0 ; i < n ; i++) mp[arr[i]]++;
        if( mp[0]%2 != 0) return false;
        for( int i = 1 ; i <= k/2 ; i++){
            if( mp[i] != mp[k-i] ) return false;
        }
        return true;
    }
};
