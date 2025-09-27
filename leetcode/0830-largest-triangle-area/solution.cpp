class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double maxarea = 0;
        for( int i = 0 ; i < n-2 ; i++ ){
            for( int j = 1 ; j < n-1 ; j++ ){
                for( int k = 2 ; k < n ; k++ ){
                    if( i != j && j != k && i != k ){
                        double area = points[i][0]*(points[j][1] - points[k][1]) + points[j][0]*(points[k][1] - points[i][1]) + points[k][0]*(points[i][1] - points[j][1]);
                        if( area < 0 ) area *= -1;
                        area /= 2;
                        maxarea = max(area,maxarea);
                    }
                }
            }
        }
        return maxarea;
    }
};
