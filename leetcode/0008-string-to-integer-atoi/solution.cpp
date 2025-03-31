class Solution {
public:
    void startSpace(string &s){
        int idx = 0;
        for(char ch : s){
            if( ch != 32) break;
            idx++;
        }
        s = s.substr(idx);
    }
    void leadZero(string &s){
        int idx = 0;
        for(char ch : s){
            if( ch != 48) break;
            idx++;
        }
        s = s.substr(idx);
    }
    int myAtoi(string s) {
        startSpace(s);
        bool b = true;
        if(s[0] == '-') {
            b = false;
            s = s.substr(1);
        }
        else if(s[0] == '+')  s = s.substr(1);
        leadZero(s);
        if( '1' > s[0] || s[0] > '9') return 0;
        long long int ans = 0;
        for( char ch: s){
            if( '0' > ch || ch > '9') break;
            if(ans > INT_MAX){
                if( b == true) return INT_MAX;
                else return INT_MIN;
            }
            ans *= 10;
            ans += (int)(ch-48);
        }
        if(b == false) ans = -ans;
        if( ans <= INT_MIN) return INT_MIN;
        if( ans >= INT_MAX) return INT_MAX;
        return ans;
    }
};
