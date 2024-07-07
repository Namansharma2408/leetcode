class Solution {
public:
    int xorOperation(int n, int start) {
        int b = 0;
        for( int i=0  ; i< n; i++){
            b = b^(start+2*i);
        }
        return b;
    }
};
