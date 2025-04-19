class Solution {
public:
    long long calculateScore(string s) {
        vector<stack<pair<char,int>>> vsp(13);
        int n = s.size();
        long long ans = 0;
        for( int i = 0 ; i < n ; i++){
            char ch = s[i];
            if( ch <= 'm'){
                if( vsp[ch-'a'].empty()){
                    vsp[ch-'a'].push({ch,i});
                }else if( vsp[ch-'a'].top().first + ch == 'a'+'z'){
                    ans += i - vsp[ch-'a'].top().second;
                    vsp[ch-'a'].pop();
                }else vsp[ch-'a'].push({ch,i});
            }else if( ch > 'm'){
                if( vsp['z' - ch].empty()){
                    vsp['z' - ch].push({ch,i});
                }else if( vsp['z' - ch].top().first + ch == 'a'+'z'){
                    ans += i - vsp['z' - ch].top().second;
                    vsp['z' - ch].pop();
                }else vsp['z' - ch].push({ch,i});
            }
        }
        return ans;
    }
};
