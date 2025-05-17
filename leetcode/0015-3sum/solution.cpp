class Solution {
public:
    vector<int> find(vector<int> &nums,int i,int j){
        int n = nums.size();
        int lo = j+1;
        int hi = n-1;
        vector<int> v;
        int num = -nums[i]-nums[j];
        while( lo <= hi){
            int mid = (lo+hi)/2;
            if(nums[mid] == num){
                v = {nums[i],nums[j],nums[mid]};
                break;
            }else if(nums[mid] < num) lo = mid + 1;
            else hi = mid - 1;
        }
        return v;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        set<vector<int>> v;
        for( int i = 0 ; i < n - 2 ; i++){
            for( int j = i+1 ; j < n - 1 ; j++){
                vector<int> temp = find(nums,i,j);
                if(temp.size() == 3) v.insert(temp);
            }
        }
        vector<vector<int>> result(v.begin(),v.end());
        return result;
    }
};
