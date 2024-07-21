class Solution {
public:
    bool isHappy(int n) {
        int a = 0;
        if( n == 1 || n == 7 ) return true;
        while( n/10 != 0){
            while( n != 0){
                a += (n%10)*(n%10);
                n /= 10;
            }
            n = a;
            if( a == 1 || a == 7) return true;
            a = 0;
        }
        return false;
    }
};
