class Solution {
public:
    bool isPowerOfThree(int n) {
        bool b = false;
        long int i = 1;
        while( i <= n){
            if( i == n) b = true;
            i *=3;
        }
        return b;
    }
};
