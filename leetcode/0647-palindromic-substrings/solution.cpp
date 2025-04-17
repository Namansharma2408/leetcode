class Solution {
public:
    int odd(string &s,int idx,int n){
        int ans = 1;
        int i = 1;
        while( idx - i >= 0 && idx + i < n){
            if( s[idx-i] == s[idx+i]) ans++;
            else break;
            i++;
        }
        return ans;
    }
    int even(string &s,int idx,int n){
        int ans = 1;
        int i = 1;
        while( idx - i >= 1 && i+idx < n){
            if( s[idx-i-1] == s[idx+i]) ans++;
            else break;
            i++;
        }
        return ans;
    }
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        for( int i = 0 ; i < n ; i++) ans += odd(s,i,n);
        for( int i = 1 ; i < n ; i++) if( s[i] == s[i-1]) ans += even(s,i,n);
        return ans;
    }
};
