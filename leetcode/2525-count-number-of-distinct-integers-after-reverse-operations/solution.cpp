class Solution {
public:
    int reverseInt(int num){
        int rev = 0;
        while( num != 0){
            rev *= 10;  
            rev += num%10;
            num /= 10;
        }
        return rev;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        for( int i : nums){
            s.insert(i);
            s.insert(reverseInt(i));
        }
        return s.size();
    }
};
