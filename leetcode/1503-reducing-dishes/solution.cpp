class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        int sum = 0;
        for( int i = n-2 ; i >= 0 ; i--) satisfaction[i] += satisfaction[i+1];
        for( int i = n-1 ; i >= 0 ; i--){
            if( satisfaction[i] < 0) break;
            sum += satisfaction[i];
        }
    return sum;
    }
};
