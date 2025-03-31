class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = 1;
        int n = nums.size();
        int ans = 0;
        while( j < n){
            if(nums[i] < nums[j])ans++,i++;
            j++;
        }
        return ans;
    }
};
