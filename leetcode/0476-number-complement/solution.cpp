class Solution {
public:
    int findComplement(int num) {
        long i = 1;
        while( true){
            if( num < i) return (i - num - 1);
            i *= 2;
        }
        return 0;
    }
};
