class Solution {
public:
    int minPartitions(string n) {
        char maxi = INT_MIN;
        int s = n.size();
        for( int i = 0 ; i < s ; i++ ){
            maxi = max(maxi,n[i]);
        }
        return int(maxi-'0');
    }
};
