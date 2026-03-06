class Solution {
public:
    bool checkOnesSegment(string s) {
        int curr = 0;
        int n = s.size();
        for( int i = 0 ; i < n-1 ; i++ ){
            if( s[i] == '1' && s[i+1] == '0' ) curr++;
            else if( s[i] == '0' && s[i+1] == '1') curr++;
            if( curr >= 2 ) return false;
        }
        if( curr >= 2 ) return false;
        return true;
    }
};
