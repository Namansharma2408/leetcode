class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> v;
        char flag = s[0];
        int n = s.size();
        int count = 1;
        for( int i = 1 ; i < n ; i++ ){
            if( s[i] == flag ){
                count++;
            }
            else {
                v.push_back(count);
                count = 1;
                flag = s[i];
            }
        }
        v.push_back(count);
        // for( int i : v ){
        //     cout<<i<<" ";
        // }
        int ans = 0;
        n = v.size();
        for( int i = 1 ; i < n ; i++ ){
            ans +=  min(v[i],v[i-1]);
        }
        return ans;
    }
};
