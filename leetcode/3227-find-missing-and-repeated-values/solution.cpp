class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int a,b;
        int n = grid.size();
        vector <bool> arr(n*n,0);
        vector<int> brr;
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < n ; j++){
                if(arr[ grid[i][j]-1] == 0) arr[ grid[i][j]-1] = 1;
                else brr.push_back(grid[i][j]);
            } 
        }
        for( int i = 0; i < n*n ; i++){
            if( arr[i] == 0) brr.push_back(i+1);
        }
        return brr;
    }
};
