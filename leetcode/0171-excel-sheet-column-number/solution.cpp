class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        int n = s.size();
        for( int i = 0 ; i < n ; i++ ){
            ans *= 26;
            ans += (s[i] - 'A' + 1);
        }
        return ans;
    }
};
