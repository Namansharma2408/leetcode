class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int ans = 0;
        float maxi = 0;
        for( int i = 0 ; i < n ; i++ ){
            float f = sqrt(dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1]);
            if( maxi < f ){
                maxi = f;
                ans = dimensions[i][0]*dimensions[i][1];
            } else if ( maxi == f ){
                int x = dimensions[i][0]*dimensions[i][1];
                if( x > ans ){
                    maxi = f;
                    ans = x;
                }
            }
        }
        return ans;
    }
};
