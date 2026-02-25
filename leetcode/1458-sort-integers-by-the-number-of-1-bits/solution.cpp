class Solution {
public:
    static bool custom(vector<int> &a, vector<int> &b){
        if( a[1] < b[1] ) return true;
        if( a[1] > b[1] ) return false;
        if( a[0] < b[0] ) return true;
        if( a[0] > b[0] ) return false;
        return false;
    }
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> v(n,vector<int>(2,0));
        for( int i = 0 ; i < n ; i++ ){
            v[i][0] = arr[i];
            v[i][1] = __builtin_popcount(arr[i]);
            // cout<<v[i][0]<<" "<<v[i][1]<<endl;
        }
        sort(v.begin(),v.end(),custom);
        for( int i = 0 ; i < n ; i++ ){
            arr[i] = v[i][0];
        }
        return arr;
    }
};
