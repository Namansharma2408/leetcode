class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        int m = values.size();
        int n = values[0].size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for( int i = 0 ; i < m ; i++){
            pq.push({values[i][n-1],i});
        }
        long long ans = 0;
        long long day = 1;
        vector<int> index(m,n-2);
        while( !pq.empty()){
            auto [val,idx] = pq.top();
            pq.pop();
            ans += day*((long long)val);
            if( index[idx] >= 0 ){
                pq.push({values[idx][index[idx]],idx});
                index[idx]--;
            }
            day++;
        }
        return ans;
    }
};
