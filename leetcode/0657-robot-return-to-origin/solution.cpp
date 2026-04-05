class Solution {
public:
    bool judgeCircle(string moves) {
        int hor = 0;
        int vert = 0;
        int n = moves.size();
        if( n%2 == 1 ) return false;
        for( int i = 0 ; i < n ; i++ ){
            if( moves[i] == 'L' ) hor--;
            else if( moves[i] == 'R' ) hor++;
            else if( moves[i] == 'U' ) vert--;
            else if( moves[i] == 'D' ) vert++;
        }
        if( hor == 0 && vert == 0 ) return true;
        return false;
    }
};
