class Solution {
public:
    string removeStars(string s) {
        string str ;
        str.push_back(s[0]);
        int n = s.size();
        for( int i = 1 ; i < n ; i++){
            if(s[i] == '*') str.pop_back();
            else str.push_back(s[i]);
        }
        return str;
    }
};
