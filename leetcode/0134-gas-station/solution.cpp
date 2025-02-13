class Solution {
public:
    bool check(vector<int> gas){
        int ans = 0;
        for( int i : gas) ans += i;
        if( ans >= 0) return true;
        else return false;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for( int i = 0 ; i < n ; i++) gas[i] -= cost[i];
        if( !check(gas)) return -1;
        for( int i = 1 ; i < n ; i++) gas[i] += gas[i-1];
        int min = 0;
        for( int i = 1 ; i < n ; i++) if(gas[min] > gas[i]) min = i;
        if( min < n-1) return min+1;
        else return 0;
    }
};
