class Solution {
public:
    int mySqrt(int x) {
        long int i;
        while(i*i <= x) i++;
        return (i-1);
        
    }
};
