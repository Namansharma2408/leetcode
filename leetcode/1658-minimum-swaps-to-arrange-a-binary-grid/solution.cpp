class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> v(n);
        for( int i = 0 ; i < n ; i++ ){
            int count = 0;
            int j = n-1;
            while( grid[i][j--] == 0 && j >= 0 ) count++;
            v[i] = count;
        }
        int diff = 0;
        for( int i = 0 ; i < n ; i++ ){
            int req = n - i - 1;
            if( v[i] < req ){
                int j = i+1;
                for( j = i+1 ; j < n ; j++ ){
                    if( v[j] >= req ) break;
                }
                if( j == n ) return -1;
                for( int k = j-1 ; k >= i ; k-- ){
                    swap(v[k],v[k+1]);
                }
                diff += j-i;
            }
            // for( int j = 0 ; j < n ; j++ ){
            //     cout<< v[j] <<" ";
            // }
            // cout<<endl;
        }
        return diff;
    }
};
