class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> vstr;
        for( int i = 1 ; i < n ; i++) {
            string s =  "1/" ;
            s.append(to_string(i));
        }
        for( int i = 2 ; i <= n ; i++){
            for( int j = 1 ; j < i ; j++){
                if( gcd(i,j) == 1 || j == 1){
                    string s = to_string(j);
                    s.append("/");
                    s.append(to_string(i));
                    vstr.push_back(s);
                }
            }
        }
        return vstr;
    }
};
