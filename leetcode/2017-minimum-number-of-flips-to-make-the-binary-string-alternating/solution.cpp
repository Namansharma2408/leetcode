class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s = s + s;
        s.pop_back();
        string s1(s.size(),'0');
        string s2(s.size(),'0');
        int m = s.size();
        for( int i = 0 ; i < m ; i++ ){
            if( i%2 != 0 ){
                s1[i] = '0';
                s2[i] = '1';
            } else {
                s1[i] = '1';
                s2[i] = '0';
            }
        }
        int flip1 = 0;
        int flip2 = 0;
        for( int i = 0 ; i < n ; i++ ){
            if( s[i] != s1[i] ) flip1++; 
        }
        flip2 = n - flip1;
        int ans = min(flip1,flip2);
        for( int i = 1 ; i < n ; i++ ){
            if( s[i-1] == s1[i-1] )flip2--;
            else flip1--;
            if( s[n+i-1] == s1[n+i-1] ) flip2++;
            else flip1++;
            ans = min(ans,min(flip1,flip2));
        }
        return ans;
    }
};
