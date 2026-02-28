class Solution {
public:
    int mod = 1e9 + 7;
    int count(int x){
        int ans = 0;
        while( x ){
            ans++;
            x /= 2;
        }
        return ans;
    }
    long long powcustom(int base,int expo){
        if( expo == 0 ) return 1;
        if( expo == 1 ) return base;
        long long ans = powcustom(base,expo/2);
        ans %= mod;
        ans *= ans;
        ans %= mod;
        if( expo%2 == 1 ) ans *= base;
        ans %= mod;
        return ans;
    }
    int concatenatedBinary(int n) {
        long long ans = 0;
        int power = 0;
        n++;
        
        while( n-- ){
            ans += powcustom(2,power)*n;
            ans %= mod;
            power += count(n);
        }
        return ans;

    }
};
