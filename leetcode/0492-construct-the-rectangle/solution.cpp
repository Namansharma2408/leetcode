class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(area);
        int l = area/w;
        while( w >= 1){
            if( l*w == area) return {l,w};
            else if( l*w < area) l++;
            else w--;
        }
        return {l,w};
    }
};
