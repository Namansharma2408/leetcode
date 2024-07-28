class Solution {
public:
    bool isPS( int square){
        int root = sqrt(square);
        if( root * root == square) return true;
        return false;
    }
    bool judgeSquareSum(int c) {
        int x = 0 ; 
        int y = c ;
        while( x <= y){
            if( isPS(x) == true && isPS(y) == true) return true;
            else if( isPS(y) == false){
                y = (int)sqrt(y)* (int)sqrt(y);
                x = c - y ;
            }
            else {
                x = ( (int)sqrt(x) + 1)*( (int)sqrt(x) + 1);
                y = c - x;
            }
        }
        return false;
    }
};
