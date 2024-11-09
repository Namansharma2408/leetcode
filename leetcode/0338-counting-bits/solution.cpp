class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v(n+1);
        v[0] = 0;
        int i = 1;
        while( i <= n){
            for( int j = i ; j < 2*i ; j++){
                if( j <= n) v[j] = v[j-i] + 1;
            }
            i *= 2;
        }
        return v;
    }
};
