class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(target > x + y) return false;
        while(y){
            x %= y;
            swap(x,y);
        }
        if( target%x == 0) return true;
        else return false;
    }
};
