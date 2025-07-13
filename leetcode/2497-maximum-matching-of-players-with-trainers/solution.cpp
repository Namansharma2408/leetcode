class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int ans = 0;
        int i = 0;
        int j = 0;
        while( j < trainers.size()){
            if(i >= players.size()) return ans;
            if(players[i] <= trainers[j]) ans++,i++;
            j++;
        }
        return ans;
    }
};
