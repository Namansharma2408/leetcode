class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        int i = 0;
        for( i = 0 ; i+k <= n ; i += 2*k) reverse(s.begin()+i,s.begin()+i+k);
        if( n - i <= k) reverse(s.begin()+i,s.end());
        else reverse(s.begin()+i,s.begin()+i+k);
        return s;
    }
};
