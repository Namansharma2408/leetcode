class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        int i = 0;
        while( i < 32 ){
            ans *= 2;
            ans += n%2;
            n /= 2;
            i++;
        }
        return ans;
        
    }
};
