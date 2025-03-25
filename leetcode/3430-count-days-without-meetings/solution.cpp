class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        for(auto i : meetings) cout<<i[0]<<" "<<i[1]<<endl;
        vector<vector<int>> ans;
        int n = meetings.size();
        ans.push_back(meetings[0]);
        
        for( auto meeting : meetings){
            if( ans.empty() || meeting[0] > ans.back()[1]) ans.push_back(meeting);
            else ans.back()[1] = max(ans.back()[1],meeting[1]);
        }
        int count = 0;
        n = ans.size();
        if( ans[0][0] > 1) count += ans[0][0] - 1;
        for( int i = 1 ; i < n ; i++) count += ans[i][0] - ans[i-1][1] - 1;
        if( ans[n-1][1] < days) count += days - ans[n-1][1];
        return count;
        
    }
};
