class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int lo = 0;
        int hi = n-1;
        while( lo < hi){
            if( numbers[lo] + numbers[hi] == target){
                vector<int> v;
                v.push_back(lo+1);
                v.push_back(hi+1);
                return v;
            }else if ( numbers[lo] + numbers[hi] < target ) lo++;
            else hi--;
        }
        return {0,1};
    }
};
