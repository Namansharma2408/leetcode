class Solution {
public:
    string convert(string s, int numRows) {
        string str;
        if( numRows ==1) return s;
        int n = s.size();
        int k = (n - (n%(numRows - 1)) - 1)/(numRows-1);
        for( int i = 0; i <= k/2 +1 ; i++){
        if(i*(2*numRows - 2) < n )   str.push_back(s[i*(2*numRows - 2)]);
        }
        for( int t = 1 ; t < (numRows-1) ; t++){
            for( int i = 0 ; i <= k/2 +1 ; i++){
            if(i*(2*numRows - 2) +t < n )    str.push_back(s[i*(2*numRows - 2) +t]);
            if((i+1)*(2*numRows - 2) - t < n )    str.push_back(s[(i+1)*(2*numRows - 2) - t]);
            }
        }


        for( int i = 0 ; i <= (k+1)/2 ; i++){
        if(i*(2*numRows - 2) + numRows - 1 < n )    str.push_back(s[i*(2*numRows - 2) + numRows - 1]);
        }
        return str;
    }
};
