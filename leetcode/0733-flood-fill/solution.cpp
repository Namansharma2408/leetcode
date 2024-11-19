class Solution {
public:
    void dfs( vector<vector<int>>& image, int sr, int sc, int color,int m , int n,int orignalcolor){
        image[sr][sc] = color;
        if( sr >= 1 && image[sr-1][sc] == orignalcolor) dfs(image,sr-1,sc,color,m,n,orignalcolor);    
        if( sr < m-1 && image[sr+1][sc] == orignalcolor) dfs(image,sr+1,sc,color,m,n,orignalcolor);
        if( sc >= 1 && image[sr][sc-1] == orignalcolor) dfs(image,sr,sc-1,color,m,n,orignalcolor);
        if( sc < n-1 && image[sr][sc+1] == orignalcolor) dfs(image,sr,sc+1,color,m,n,orignalcolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int orignalcolor = image[sr][sc];
        if( orignalcolor != color) dfs(image,sr,sc,color,m,n,orignalcolor);
        return image;
    }
};
