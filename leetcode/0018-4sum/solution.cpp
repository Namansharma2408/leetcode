class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4 ) return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int k,l;
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1  &&  nums[j] == nums[j - 1]) {continue;}
             k=j+1;
             l=nums.size()-1;
             while(k<l){
                long long sum=(long long)nums[i]+nums[j]+nums[k]+nums[l];
            if(sum==target){
             ans.push_back({nums[i],nums[j],nums[k],nums[l]});
     k++;
while (k < l && nums[k] == nums[k - 1]) k++;

l--;
while (k < l && nums[l] == nums[l + 1]) l--;

            }
            else if(sum>target){
            l--;
            }
            else{
            k++;    
            }
             }
          }
        }
        return ans;
    }
};
