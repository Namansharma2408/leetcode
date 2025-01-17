class Solution {
public:
    int reverse(int x) {
        bool b = true;
        if( x >= 0) b = true;
        else if( x == INT_MIN) return 0;
        else b = false, x = -x;
        int n = 0;
        while( x != 0){
            if( n > INT_MAX/10) return 0;
            n *= 10;
            if( n > INT_MAX - x%10) return 0;
            n += x%10;       
            x /= 10;
        }
        if(b)return n;
        return -n;
    }
};
