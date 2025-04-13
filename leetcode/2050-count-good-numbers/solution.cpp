#define ll long long
class Solution {
    ll power( int base,ll exp){       
        if( exp == 1) return base;
        if( exp == 0) return 1;
        ll p = (power(base,exp/2));
        p = ((p%(ll)(1000000007))*(p%(ll)(1000000007)))%(ll)(1000000007);
        if( exp%2 == 1) p *= base%(1000000007);
        return p%(1000000007);
    }
public:
    int countGoodNumbers(long long n) {
        ll ans = 1;
        ans *= (ll)power(20,n/2)%(1000000007);       
        if( n%2 == 1) ans *= 5;
        ans %= (1000000007);
        return (int)ans;
        
    }
};
