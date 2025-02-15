class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drink = numBottles;
        int empty = numBottles;
        numBottles = 0;
        while( empty >= numExchange ){
            empty -= numExchange;
            drink++;
            numExchange++;
            empty++;
        }
        return drink;
    }
};
