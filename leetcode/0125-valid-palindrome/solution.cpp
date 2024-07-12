class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        int i = 0;
        for( i = 0 ; i < s.size() ; i++){
            if( 65 <= int(s[i]) && int(s[i]) <= 90) str += char(s[i] + 32);
            else if ( 97 <= int(s[i]) && int(s[i]) <= 122 ) str += s[i] ;
            else if ( 48 <= int(s[i]) && int(s[i]) <= 57) str += s[i] ;
        }
        i = 0;
        int j = str.size()-1;
        while( i < j ){
            if( str[i] != str[j]) return false;
            i++,j-- ;
        }
        return true;
    }
};
