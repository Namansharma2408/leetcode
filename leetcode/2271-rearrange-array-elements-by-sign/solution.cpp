class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> q1;
        queue<int> q2;
        int n = nums.size();
        for( int i = 0 ; i < n ; i++){
            if( nums[i] > 0 ) q1.push(nums[i]);
            if( nums[i] < 0 ) q2.push(nums[i]);
        }
        for( int i = 0 ; i < n ; i += 2){
            nums[i] = q1.front();
            nums[i+1] = q2.front();
            q1.pop(),q2.pop();
        }
        return nums;
        
    }
};
