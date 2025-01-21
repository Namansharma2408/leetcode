class Solution {
public:
    bool isVowel(char c){
        if(c == 'a') return true;
        if(c == 'e') return true;
        if(c == 'i') return true;
        if(c == 'o') return true;
        if(c == 'u') return true;
        if(c == 'A') return true;
        if(c == 'E') return true;
        if(c == 'I') return true;
        if(c == 'O') return true;
        if(c == 'U') return true;
        return false;
    }
    string reverseVowels(string s) {
        int i = 0;
        int n = s.size();
        int j = n-1;
        while( i < j){
            bool si = isVowel(s[i]);
            bool sj = isVowel(s[j]);
            if( si && sj ) swap(s[i],s[j]),i++,j--;
            else if( si ) j--;
            else if( sj ) i++;
            else i++,j--;
        }
        return s;
    }
};
