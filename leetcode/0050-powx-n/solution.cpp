class Solution {
public:
    double power( double x , int n){
        if( n == 1) return x;
        double y = power( x, n/2)*power( x , (n+1)/2);
        return y;
    }
    double myPow(double x, int n) {
        if( n == 0 || x == 1) return 1;
        else if ( x == -1) return( n%2 == 0 ? 1 : -1);
        else if( abs(x) > 0 && abs(x) < 0.5 && n > 50 ) return 0;
        else if( x >=2   && n < -50 ) return 0;
        else if( n > 0 ) return (power(x,n));
        else return (1/(power(x,-n)));
        
    }
};
