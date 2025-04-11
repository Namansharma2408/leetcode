class Solution {
public:
    int f( int n){
        int a = n%10;
        n /= 10;
        int b = n%10;
        n /= 10;
        int c = n%10;
        n /= 10;
        int d = n%10;
        if( a + b == c + d) return 1;
        else return 0;
    }
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        if( high <= 10 ) return 0;
        if ( low < 100) {
            int lo = max(low,11);
            int hi = min(high,99);
            for( int i = lo ; i <= hi ; i++){
                if( i%11 == 0) ans++;
            }
        }
        if( high > 1000){
            int lo = max(low,1001);
            int hi = min(high,9999);
            for( int i = lo  ; i <= hi ; i++) ans += f(i);
        }
        return ans;
    }
};
