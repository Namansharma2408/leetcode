class Solution {
public:
    int minOperations(string s) {
        int zerostart = 0;
        int onestart = 0;
        int n = s.size();
        for( int i = 0 ; i < n ; i++ ){
            if( i%2 == 0 ){
                if( s[i] == '0' ) onestart++;
                else zerostart++;
            } else {
                if( s[i] == '1' ) onestart++;
                else zerostart++;
            }
        }
        return min(onestart,zerostart);
    }
};
