class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0 ) return false;
       string s = to_string(x);
       int n = s.size();
        bool b = true;
       for( int i = 0 ; i < n/2 ; i++){
        if( s[i] != s[n-1-i])  b = false;
       } 
       if( b == true) return true;
       else return false;
    }
};
