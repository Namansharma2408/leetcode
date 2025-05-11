class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev_n= 0;
        for(int i = 0 ; i < 32 ; i++){
            rev_n *= 2;
            rev_n += n%2;
            n /= 2;
        }
        return rev_n;
    }
};
