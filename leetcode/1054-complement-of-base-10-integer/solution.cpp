class Solution {
public:
    int bitwiseComplement(int n) {
        int num = 1;
        while( num < n ){
            num *= 2;
            num += 1;
        }
        return num - n;
    }
};
