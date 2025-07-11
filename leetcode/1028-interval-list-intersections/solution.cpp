class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        vector<vector<int>> v;
        int n1 = f.size();
        int n2 = s.size();
        if( n1 == 0 || n2 == 0) return v;
        if(f[0][0] > s[n2-1][1] || f[n1-1][1] < s[0][0]) return v;
        int i = 0;
        int j = 0;
        while( i < n1 && j < n2 ){
            if( max(f[i][0],s[j][0]) <= min(f[i][1],s[j][1])){
                v.push_back({max(f[i][0],s[j][0]),min(f[i][1],s[j][1])});
                if(f[i][1] == s[j][1]) i++,j++;
                else if(f[i][1] < s[j][1]) i++;
                else j++;
            }else if(f[i][1] < s[j][1]) i++;
            else j++;
        }
        return v;

    }
};
