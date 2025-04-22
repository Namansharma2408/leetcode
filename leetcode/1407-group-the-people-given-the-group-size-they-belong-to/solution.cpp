class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        unordered_map<int,vector<int>> mp;
        int n = gs.size();
        for( int i = 0 ; i < n ; i++) mp[gs[i]].push_back(i);
        vector<vector<int>> ans;
        for( auto i : mp){
            for( int j = 0 ; j < i.second.size() ; j += i.first){
                vector<int> v(i.second.begin()+j,i.second.begin()+j+i.first);
                ans.push_back(v);
            }
        }
        return ans;
    }
};
