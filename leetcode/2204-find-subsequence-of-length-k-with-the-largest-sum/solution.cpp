class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n = nums.size();
        for( int i = 0 ; i < n ; i++ ){
            pq.push({nums[i],i});
            if( pq.size() > k ) pq.pop();
        }
        vector<vector<int>> v(k,vector<int>(2,0));
        for( int i = 0 ; i < k ; i++ ){
            auto p = pq.top();
            v[i][0] = p.first;
            v[i][1] = p.second;
            pq.pop();
        }
        sort(v.begin(),v.end(), []( const vector<int>&a, const vector<int>&b ){
            if( a[1] < b[1] ) return true;
            if( a[1] > b[1] ) return false;
            if( a[0] < b[0] ) return true;
            if( a[0] > b[0] ) return false;
            return false;
        });
        vector<int> ans(k);
        for( int i = 0 ; i < k ; i++ ){
            ans[i] = v[i][0];
        }
        return ans;
    }
};
