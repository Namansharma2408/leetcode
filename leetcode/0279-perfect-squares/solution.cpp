class Solution {
public:
    int mini(vector<int>&v , int idx){
        int m = INT_MAX;
        for( int p = 1 ; p*p < idx ; p++ ){
            m = min(m,v[idx-p*p]);
        }
        return m;
    }
    int numSquares(int n) {
        vector<int> v(n+1,0);
        v[1] = 1;
        for( int i = 1 ; i*i <= n ; i++) v[i*i] = 1;
        if( v[n] == 1) return 1;
        for( int i = 2; i <= n ; i++){
            if(v[i] == 0 )v[i] = 1+ mini(v,i);
        }
        return v[n];
    }
};
