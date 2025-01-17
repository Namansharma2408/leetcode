class Solution {
public:
    string convert(string s, int numRows) {
        if( numRows == 1) return s;
        string str = "";
        int n = s.size();
        // For the 1st row
        for(int i = 0 ; i < n ; i += 2*(numRows-1)) str.push_back(s[i]);
        
        // For all other rows other than last
        for( int i = 1 ; i <= numRows-2 ; i++){
            for( int j = 0 ; j < 2*n ; j += 2*(numRows-1)){
                if(j-i >= 0 && j-i < n)str.push_back(s[j-i]);
                if(j+i < n)str.push_back(s[j+i]);
            }
        }

        // For last row 
        for( int i = numRows-1 ; i < n ; i += 2*(numRows-1)) str.push_back(s[i]);

        return str;
    }
};
