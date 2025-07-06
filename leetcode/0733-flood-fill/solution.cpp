class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if( image[sr][sc] == color) return image;
        int m = image.size();
        int n = image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int c = image[sr][sc];
        image[sr][sc] = color;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            image[p.first][p.second] = color;
            if(p.first > 0 && c == image[p.first-1][p.second] ) {
                q.push({p.first-1,p.second});
                image[p.first-1][p.second] = color; 
            }
            if(p.second > 0 && c == image[p.first][p.second-1] ) {
                q.push({p.first,p.second-1});
                image[p.first][p.second-1] = color;   
            }
            if(p.first < m-1 && c == image[p.first+1][p.second] ) {
                q.push({p.first+1,p.second});
                image[p.first+1][p.second] = color;    
            }
            if(p.second < n-1 && c == image[p.first][p.second+1] ) {
                q.push({p.first,p.second+1});
                image[p.first][p.second+1] = color;  
            }
        }
        return image;
    }
};
