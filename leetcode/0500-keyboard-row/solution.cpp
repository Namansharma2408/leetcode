class Solution {
public:
    bool find(unordered_set<char> &row,string s){
        int n = s.size();
        for( int i = 1 ; i < n ; i++){
            if( row.find(s[i]) == row.end()) return false;
        }
        return true;
    }
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> row1 = {'q','w','e','r','t','y','u','i','o','p','Q','W','E','R','T','Y','U','I','O','P'};
        unordered_set<char> row2 = {'a','s','d','f','g','h','j','k','l','A','S','D','F','G','H','J','K','L'};
        unordered_set<char> row3 = {'z','x','c','v','b','n','m','Z','X','C','V','B','N','M'};
        vector<string> vs;
        int n = words.size();
        for( int i = 0 ; i < n ; i++){
            string str = words[i];
            if( row1.find(str[0]) != row1.end() ){
                if(find(row1,str)) vs.push_back(str);
            }
            else if( row2.find(str[0]) != row2.end() ){
                if(find(row2,str)) vs.push_back(str);
            }
            else if( row3.find(str[0]) != row3.end() ){
                if(find(row3,str)) vs.push_back(str);
            }
        }
        return vs;
    }
};
