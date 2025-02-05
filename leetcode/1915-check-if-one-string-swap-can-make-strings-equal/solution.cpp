class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if( s1 == s2 ) return true;
        int n = s1.size();
        int count = 0;
        for( int i = 0 ; i < n ; i++){
            if( s1[i] != s2[i] ){ 
                count++;
                s1 = s1 + s1[i];
                s2 = s2 + s2[i];
            }
        }
        if( count == 2 && s1[n] == s2[n+1] && s1[n+1] == s2[n]) return true;
        else return false;
    }
};
