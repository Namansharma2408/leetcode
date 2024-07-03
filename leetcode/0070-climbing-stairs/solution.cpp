class Solution {
public:
    int climbStairs(int n) {
        if( n==1  ) return 1;
        if( n==2  ) return 2;
        int a = 1;
        int ans = 2;
        for(int i = 3 ; i <= n ; i++){
            ans = ans + a;
            a = ans - a;
        }
        return ans;
    }
};
