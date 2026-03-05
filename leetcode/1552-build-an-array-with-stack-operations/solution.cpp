class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> vs;
        int m = target.size();
        int idx = 0;
        for( int i = 1 ; i <= n ; i++ ){
            if( idx < m && target[idx] == i ){
                vs.push_back("Push");
                idx++;
                if( idx == m ) break;
            } else {
                vs.push_back("Push");
                vs.push_back("Pop");
            }
        }
        return vs;
    }
};
