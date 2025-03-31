class Solution {
public:
    bool isPalindrome(string s,int n){
        for( int i = 0 ; i < n/2 ; i++)if(s[i] != s[n-i-1]) return false;
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        if(isPalindrome(s,n)) return true;
        int i = 0 , j = n-1;
        while( i <= j){
            if( s[i] != s[j]){
                if( i == j -1) return true;
                if( isPalindrome(s.substr(i,j-i),j-i) || isPalindrome(s.substr(i+1,j-i),j-i)) return true;
                else return false;
            }
            else i++,j--;
        }
        return false;
    }
};
