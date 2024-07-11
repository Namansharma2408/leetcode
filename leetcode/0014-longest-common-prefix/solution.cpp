class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if( strs.size()==1 ) return strs[0];
        string s = "";
        int minsize = strs[0].size();
        for( int i = 0 ; i < strs.size(); i++)if( minsize > strs[i].size()) minsize = strs[i].size();
        for( int i = 0; i<minsize ; i++){
            bool b = true;
            for( int j = 1; j< strs.size() ; j++ ){
                if( strs[0][i] != strs[j][i]) b = false;
            }
            if( b == true) s+= strs[0][i];
            else return s;
        }
        return s;
    }

};
