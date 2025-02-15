class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans ;
        if(k >= numOnes ) ans = numOnes;
        else return k;
        k -= numOnes;
        k -= numZeros;
        if(k <= 0) return ans;
        else{
            if(k >= numNegOnes) return ans - numNegOnes;
            else return ans - k;
        }
    }
};
