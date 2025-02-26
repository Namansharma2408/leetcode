class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int present = 0;
        int x = 0;
        while(true){
            if( present >= target && (present-target)%2 == 0) return x;
            present += ++x;
        }
        return x;
    }
};
