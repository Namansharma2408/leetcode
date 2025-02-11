class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.size();
        int m = part.size();
        if( n < m) return s;
        for( int i = 0 ; i < n ; i++){
            if(s.substr(i,m) == part){
                s = s.substr(0,i) + s.substr(i+m);
                break;
            } 
            
        }
        if(n != s.size()) s = removeOccurrences(s,part);
        return s;
    }
};
