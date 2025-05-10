bool cmp(vector<int> &a,vector<int> &b){
    return a[1] < b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int i = 0 , ans = 0;
        int n = points.size();
        for( int j = 1 ; j < n ; j++) if( points[i][1] < points[j][0]) i = j,ans++;  
        return ans+1;
        
    }
};
