class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int oddSum = 0 , evenSum = 0;
        int n = position.size();
        for( int i = 0 ; i < n ; i++){
            if( position[i]%2 == 0) evenSum++;
            else oddSum++;
        }
        return min(oddSum,evenSum);
    }
};
