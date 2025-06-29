class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26);
        int n = s.size();
        for( int i = 0 ; i < n ; i++) v[s[i] - 'a']++;
        sort(v.begin(),v.end());
        int i = 25;
        int j = 24;
        while( j >= 0 ){
            if( v[i] <= v[j] && v[j] > 0 ) v[j] = max(v[i] - 1,0);
            i--,j--;
        }
        int ans = 0;
        for( int i = 0 ; i < 26 ; i++) ans += v[i];
        return (n-ans);
    }
};
