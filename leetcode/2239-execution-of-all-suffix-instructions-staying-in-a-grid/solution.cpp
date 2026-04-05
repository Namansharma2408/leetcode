class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& pos, string s) {
        int m = s.size();
        vector<int> v(m,-1);
        for( int i = 0 ; i < m ; i++ ){
            int curry = pos[0];
            int currx = pos[1];
            for( int j = i ; j < m ; j++ ){
                if( s[j] == 'R' ) currx++;
                else if( s[j] == 'L' ) currx--;
                else if( s[j] == 'U' ) curry--;
                else if( s[j] == 'D' ) curry++;
                if( currx < 0 || curry < 0 || currx >= n || curry >= n ) {
                    v[i] = j-i;
                    break;
                }
            }
            if(v[i] == -1 ) v[i] = m-i;
        }
        return v;

    }
};
