#define mod 1000000007
class Solution {
public:
    long long fact(int n){
        long long f = 1;
        for( int i = 2 ; i <= n ; i++) f = ((f%mod)*i)%mod;
        return (f%mod);
    }
    int numPrimeArrangements(int n) {
        vector<bool> isPrime(n+1, true);
        isPrime[0] = isPrime[1] = false;
        for (int p = 2; p*p <= n; ++p) {
            if (isPrime[p]) {
                for (int i = p*p; i <= n; i += p) {
                    isPrime[i] = false;
                }
            }
        }
        int primes = 0;
        for( int i = 1 ; i <= n ; i++){
            if(isPrime[i]) primes++;
        }
        return ((fact(n-primes)%mod)*(fact(primes)%mod))%mod;
    }
};
