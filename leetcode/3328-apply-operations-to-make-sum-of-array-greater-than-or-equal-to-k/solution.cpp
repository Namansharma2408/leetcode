class Solution {
public:
    int f(int i,int k){
        if( k%i == 0) return k/i-1;
        else return k/i;
    }
    int minOperations(int k) {
        int mini = k-1;
        for( int i = 2 ; i*i <= k ; i++){
            mini = min(mini,i+f(i,k)-1);
        }
        return mini;
    }
};
