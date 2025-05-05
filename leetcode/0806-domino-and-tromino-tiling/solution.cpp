
class Solution {
public:
    vector<int> v;
    int mod = 1000000007;
    int f(int n){
        if( n == 1) return 1;
        if( n == 2) return 2;
        if( n == 3) return 5;
        if( v[n] != -1 ) return v[n];
        return v[n] = ((2*f(n-1))%mod + f(n-3)%mod)%mod;
    }
    int numTilings(int n) {
        v.resize(n+2,-1);
        return f(n)%mod;
    }
};
