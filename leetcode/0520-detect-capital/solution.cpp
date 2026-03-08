class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if( word[0] >= 'a' && word[0] <= 'z' ){
            for( int i = 1 ; i < n ; i++ ){
                if( word[i] < 'a' || word[i] > 'z' ) return false;
            }
        }
        if( word[0] >= 'A' && word[0] <= 'Z' ){
            if( word[1] >= 'A' && word[1] <= 'Z' ){
                for( int i = 2 ; i < n ; i++ ){
                    if( word[i] < 'A' || word[i] > 'Z' ) return false;
                }
            }
            if( word[1] >= 'a' && word[1] <= 'z' ){
                for( int i = 2 ; i < n ; i++ ){
                    if( word[i] < 'a' || word[i] > 'z' ) return false;
                }
            }
        }
        return true;
    }
};
