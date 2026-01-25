class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        // exit with rook with bishops in between
        if( a == c && c == e ){
            if( b < d && d < f ) return 2;
            if( b > d && d > f ) return 2;
            return 1;
        }
        if( b == d && d == f ){
            if( a < c && c < e ) return 2;
            if( a > c && c > e ) return 2;
            return 1;
        }
        // exit with bishops with rook in between
        if( b-a == d-c && d-c == f-e ){
            if( c < a && a < e ) return 2;
            if( c > a && a > e ) return 2;
            return 1;
        }
        if( b+a == d+c && d+c == f+e ){
            if( c < a && a < e ) return 2;
            if( c > a && a > e ) return 2;
            return 1;
        }
        if( a == e || b == f ) return 1;
        if( c+d == e+f || c-d == e-f ) return 1;
        return 2;
    }
};
