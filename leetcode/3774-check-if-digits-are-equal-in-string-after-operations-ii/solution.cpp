class Solution {
public:
    int binmod10(int n, int k) {
        int mod2 = binmod2(n, k);
        int mod5 = binmod5(n, k);
        for (int i = 0; i < 10; i++) {
            if (i % 2 == mod2 && i % 5 == mod5)
                return i;
        }
        return 0;
    }

    int binmod2(int n, int k) {
        while (k > 0) {
            if ((k & 1) > (n & 1))
                return 0;
            n >>= 1;
            k >>= 1;
        }
        return 1;
    }

    int binmod5(int n, int k) {
        int res = 1;
        while (n > 0 || k > 0) {
            int nd = n % 5;
            int kd = k % 5;
            if (kd > nd)
                return 0;
            res = (res * binsmall(nd, kd)) % 5;
            n /= 5;
            k /= 5;
        }
        return res;
    }

    int binsmall(int n, int k) {
        if (k > n)
            return 0;
        int fact[5] = {1, 1, 2, 1, 4};
        int numerator = fact[n];
        int denominator = (fact[k] * fact[n - k]) % 5;
        int deninv = 0;
        for (int i = 0; i < 5; i++) {
            if ((denominator * i) % 5 == 1) {
                deninv = i;
                break;
            }
        }
        return (numerator * deninv) % 5;
    }
    bool hasSameDigits(string s) {
        int n = s.size();
        int a = 0 , b = 0;
        int multiplier = 1;
        for( int i = 0 ; i < n-1 ; i++){        
            // a block
            a = (a + (multiplier * (s[i] - '0')))%10;

            // b block
            b = (b + (multiplier * (s[i+1] - '0')))%10;
            // multiplier update
            multiplier = binmod10(n-2,i+1);
        }
        if( a == b ) return true;
        return false;
    }
};
