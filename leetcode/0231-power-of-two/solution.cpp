class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool b = false;
        for( long int i = 1 ; i <=n ; i *=2){
            if(i == n ) b = true;
        }
        return b;
    }
};
