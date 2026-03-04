class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int,int>> vp(m*n);
        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                vp[mat[i][j]-1].first = i;
                vp[mat[i][j]-1].second = j;
            }
        }
        // for( auto p : vp ){
        //     cout<<p.first<<" "<<p.second<<endl;
        // }
        vector<int> vrows(m);
        vector<int> vcols(n);
        for( int i = 0 ; i < n*m ; i++ ){
            int x = arr[i];
            vrows[vp[x-1].first]++;
            vcols[vp[x-1].second]++;
            if( vrows[vp[x-1].first] == n || vcols[vp[x-1].second] == m ) return i;
        }
        return 0;

    }
};
