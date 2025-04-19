class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string,int> mp;
        int n = word.size();
        for( int i = 0 ; i < n ; i += k) mp[word.substr(i,k)]++;
        int maxi = -1;
        for( auto i : mp) if(i.second > maxi) maxi = i.second;
        return (n/k - maxi);
        

    }
};
