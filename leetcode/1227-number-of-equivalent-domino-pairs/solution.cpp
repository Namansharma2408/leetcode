class Solution {
public:
    struct pair_hash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<pair<int,int>,int,pair_hash> mp;
        int n = dominoes.size();
        for( int i = 0 ; i < n ; i++){
            mp[{dominoes[i][0],dominoes[i][1]}]++;
            mp[{dominoes[i][1],dominoes[i][0]}]++;
        }
        int ans = 0;
        for( auto i : mp) {
            if(i.second > 1 && i.first.first != i.first.second) ans += (i.second*(i.second-1))/2;
            else if( i.first.first == i.first.second && i.second > 2 ) ans += (i.second*(i.second-2))/4;
        }
        return ans/2;
        
    }
};
