class Solution {
public:
    int fib(int n) {
        if( n == 0) return 0;
        int a = 0;
        int b = 1;
        int ans = 1;
        for( int i = 2 ; i <= n ; i++){
            ans = a+b;
            b = ans;
            a = ans - a;
        }
        return ans;
    }
};
