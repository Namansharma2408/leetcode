class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        if( n == 1){
            if( grumpy[0] == 1 && minutes == 0) return 0;
            return customers[0];
        } 
        int prevLoss = 0;
        for( int i = 0 ; i < minutes ; i++) prevLoss += customers[i]*grumpy[i];
        int maxLoss = prevLoss;
        int maxIdx = 0;
        int i = 1;
        int j = minutes;
        while( j < n ){
            int currLoss = prevLoss + customers[j]*grumpy[j] - customers[i-1]*grumpy[i-1];
            if( maxLoss < currLoss){
                maxLoss = currLoss;
                maxIdx = i;
            }
            prevLoss = currLoss;
            i++,j++;
        }
        for( int i = maxIdx ; i < maxIdx + minutes ; i++){
            grumpy[i] = 0;
        }
        int sum = 0;
        for( int i = 0 ; i < n ; i++)if( grumpy[i] == 0) sum += customers[i];
        return sum;
    }
};
