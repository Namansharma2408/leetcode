class Solution {
public:
    int findComplement(int num) {
        for( long i = 1 ;   ; i*= 2){
            if( num < i) return ( i - num - 1);
        }
        return 0;
    }
};
