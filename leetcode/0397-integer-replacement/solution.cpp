class Solution {
public:
    int integerReplacement(int n) {
        long long m = (long long)n;
        int ans = 0;
        while( m != 1){
            if( m%2 == 0) m /= 2;
            else if ( m%4 == 1 || m == 3) m -= 1;
            else m += 1;
            ans++;
        }
        return ans;
    }
};
