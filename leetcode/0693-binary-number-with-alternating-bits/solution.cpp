class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool flag = n%2;
        n /= 2;
        while( n ){
            bool b = n%2;
            if( flag == b ) return false;
            flag = b;
            n /= 2;
        }
        return true;
    }
};
