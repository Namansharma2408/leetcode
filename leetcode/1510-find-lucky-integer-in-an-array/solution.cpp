class Solution {
public:
    int findLucky(vector<int>& arr) {
        int v[500];
        int n = arr.size();
        for( int i = 0 ; i < n ; i++){
            v[arr[i]-1]++;
        }
        int maxi = -1;
        for( int i = 0 ; i < n ; i++){
            if(v[i] == i+1) maxi = v[i];
        }
        return maxi;
    }
};
