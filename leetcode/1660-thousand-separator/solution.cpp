class Solution {
public:
    string thousandSeparator(int n) {
        string s;
        if( n == 0) return "0";
        int count = 0;
        while( n != 0){
            string p = to_string(n%10);
            count++;
            s = p + s;
            if( count%3 == 0 && n > 9) s = "." + s;
            n /= 10;
            
        }
        return s;
    }
};
