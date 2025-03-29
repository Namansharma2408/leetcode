class Solution {
public:
    int gcd(int a,int b){
        while( b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    void divide(int &p , int &q){
        int x = gcd(p,q);
        p /= x;
        q /= x;
    }
    int mirrorReflection(int p, int q) {
        divide(p,q);
        if( (p - q)%2 == 0) return 1;
        if( p%2 == 0 && q%2 == 1) return 2;
        else return 0;
        
    }
};
