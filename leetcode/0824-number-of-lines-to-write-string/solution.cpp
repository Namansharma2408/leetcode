class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int n = s.size();
        int ans = 0;
        int line = 1;
        for( int i = 0 ; i < n ; i++){
            ans += widths[s[i]-'a'];
            if( ans > 100 ) ans = widths[s[i]-'a'] , line++;
        }
        return {line,ans};
    }
};
