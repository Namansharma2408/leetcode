class Solution {
public:
    int hammingDistance(int x, int y) {
        x ^= y;
        y = 0;
        while( x != 0){
            y += x%2 ;
            x /= 2;
        }
        return y;
    }
};
