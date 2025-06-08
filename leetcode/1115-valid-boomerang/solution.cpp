class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        // check if they are same
        if(points[0][0] == points[1][0] && points[0][1] == points[1][1]) return false;
        if(points[2][0] == points[1][0] && points[2][1] == points[1][1]) return false;
        if(points[0][0] == points[2][0] && points[0][1] == points[2][1]) return false;
        
        // if they are on same line
        if((points[2][1]-points[0][1])*(points[1][0]-points[0][0]) == (points[1][1]-points[0][1])*(points[2][0]-points[0][0])) return false;
        return true;

    }
};
