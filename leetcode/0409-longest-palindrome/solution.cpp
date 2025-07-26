class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        for( int i = 0 ; i < n ; i++){
            mp[s[i]]++;
        }
        int ans = 0;
        bool b = false;
        for( auto p : mp ){
            if( p.second%2 == 1) b = true;
            ans += (p.second/2)*2;
        }
        return ans+b;

    }
};
