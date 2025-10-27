class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prev = 0;
        int curr = 0;
        int m = bank.size();
        int n = bank[0].size();
        for( int i = 0 ; i < m ; i++ ){
            if(curr != 0 ) prev = curr;
            curr = 0;
            for( int j = 0 ; j < n ; j++){
                if( bank[i][j] == '1') curr++;
            }
            // cout<<prev<<" "<<curr<<endl;
            ans += prev*curr;
        }  
        return ans;
    }
};
