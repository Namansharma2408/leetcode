class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for( int i = 0 ; i < n - 1 ; i++){
            int lo = i+1;
            int hi = n-1;
            while( lo <= hi){
                int mid = (lo+hi)/2;
                if( numbers[mid] + numbers[i] == target){
                    vector<int> v(2);
                    v[0] = i+1;
                    v[1] = mid+1;
                    return v;
                }else if(numbers[mid] + numbers[i] < target) lo = mid+1;
                else hi = mid - 1;
            }

        }
        return numbers;
    }
};
