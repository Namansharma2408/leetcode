class Solution {
public:
    set<vector<int>> ans;
    vector<int> v;
    void subsets(vector<int> &nums, int idx , int n){
        if( idx == n ){
            ans.insert(v);
            return;
        }

        subsets(nums,idx+1,n);
        v.push_back(nums[idx]);
        subsets(nums,idx+1,n);
        v.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        subsets(nums,0,n);
        vector<vector<int>> finalAns(ans.begin(),ans.end());
        return finalAns;
    }
};
