class Solution {
public:
    int trailingZeroes(int n) {
        int i = 5;
        int ans = 0;
        while( n/i != 0){
            ans += n/i;
            i *= 5;
        }
        return ans;
    }
};
