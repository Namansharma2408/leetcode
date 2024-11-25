class Solution {
public:
    int addDigits(int nums) {
        int ans = 0;
        while(nums/10 != 0 ){
            while( nums != 0){
                ans += nums%10;
                nums /= 10;
            }
            nums = ans;
            ans = 0;
        }
        return nums;
    }
};
