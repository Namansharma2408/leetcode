class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 1) return true;
        if( 97 <= word[0] && word[0] <= 122){
            for( char ch : word) if( 97 > ch || ch > 122) return false;
            return true;
        }
        if( 65 <= word[0] && word[0] <= 90 ){
            if(word.size() > 1 && 65 <= word[1] && word[1] <= 90){
                for( char ch : word) if( 65 > ch || ch > 90) return false;
                return true;
            }
            if(word.size() > 1 && 97 <= word[1] && word[1] <= 122){
                int n = word.size();
                for( int i = 1 ; i < n ; i++) if( 97 > word[i] || word[i] > 122) return false;
                return true;
            }
        }
        return false;
        
    }
};
