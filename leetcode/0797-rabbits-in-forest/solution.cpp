class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        int n = answers.size();
        for( int i = 0 ; i < n ; i++) mp[answers[i]]++;
        int ans = 0;
        for( auto i : mp){
            if( i.first == 0) ans += i.second;
            else {
                ans += ((i.second)/(i.first+1))*(i.first+1);
                if( i.second%(i.first+1) > 0)  ans += i.first+1;
            }
        }
        return ans;
    }
};
