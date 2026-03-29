class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        int n = s1.size();
        for( int i = 0 ; i < n ; i++ ){
            if( i%2 == 0 ){
                mp1[s1[i]]++;
            } else {
                mp2[s1[i]]++;
            }
        }
        for( int i = 0 ; i < n ; i++ ){
            if( i%2 == 0 ){
                mp1[s2[i]]--;
                if( mp1[s2[i]] < 0 ) return false;
            } else {
                mp2[s2[i]]--;
                if( mp2[s2[i]] < 0 ) return false;
            }
        }
        return true;
    }
};
