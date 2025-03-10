class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int> pq;
        for( int i : nums){
            pq.push(i);
        }
        int n = nums.size();
        for( int i = n-1 ; i >= 0 ; i--){
            nums[i] = pq.top();
            pq.pop();
        }
        return nums;
    }
};
