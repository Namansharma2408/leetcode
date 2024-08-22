class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int filled = numBottles;
        int empty = 0;
        int total = 0;
        while( filled != 0){
            total += filled;
            empty += filled;
            filled = empty/numExchange;
            empty = empty%numExchange;
        }
        return total;
    }
};
