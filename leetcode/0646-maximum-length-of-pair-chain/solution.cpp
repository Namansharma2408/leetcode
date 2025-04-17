class Solution {
public:
    int findLongestChain(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        int end = v[0][1];
        int n = v.size();
        int ans = 1;
        for( int i = 1 ; i < n ; i++){
            if( v[i][0] > end ){
                end = v[i][1];
                ans++;
            }
        }
        return ans;
    }
};
