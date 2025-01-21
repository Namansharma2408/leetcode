class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        for( int i = 1 ; i < n ; i++) gain[i] += gain[i-1];
        int max = 0;
        for( int i = 0 ; i < n ; i++) if(max < gain[i]) max = gain[i];
        return max;
    }
};
