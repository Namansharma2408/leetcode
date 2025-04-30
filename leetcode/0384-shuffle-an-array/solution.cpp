class Solution {
public:
    vector<int> nums;
    int n;
    vector<int> copy;
    Solution(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        copy = nums;
    }
    
    vector<int> reset() {
        nums = copy;
        return nums;
    }
    
    vector<int> shuffle() {
        for( int i = 0 ; i < n ; i++) swap(nums[i],nums[rand()%n]);
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
