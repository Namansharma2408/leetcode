class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;
        int num = tickets[k];
        int n = tickets.size();
        for( int i = 0 ; i < n ; i++ ){
            if( tickets[i] < num ) ans += tickets[i];
            else if( i < k ){
                ans += min(num,tickets[i]);
            }
            else if( i > k ){
                ans += min(num-1,tickets[i]);
            }
        }
        return (ans+num);
    }
};
