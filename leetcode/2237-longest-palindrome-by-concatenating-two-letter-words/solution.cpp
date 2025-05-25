class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        int n = words.size();
        for( int i = 0 ; i < n ; i++) mp[words[i]]++;
        int ans = 0;
        bool flag = false;
        for( auto p : mp){
            string str = {p.first[1],p.first[0]};
            if( p.first == str){
                if( p.second%2 == 1) flag = true;
                ans += (p.second/2)*4;
            }
            else if( mp.find(str) != mp.end()){
                ans += min(p.second,mp[str])*4;
                p.second = 0;
                mp[str] = 0;
            }
        }
        if( flag ) ans += 2;
        return ans;
    }
};
