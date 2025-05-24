class Solution {
public:
    void permutation(vector<int> &temp,vector<vector<int>> &result,vector<bool> &visited,vector<int> &nums,int n,int x){
        if( x == n){
            result.push_back(temp);
            return;
        }
        for( int i = 0 ; i < n ; i++){
            if( !visited[i]){
                visited[i] = true;
                temp.push_back(nums[i]);
                permutation(temp,result,visited,nums,n,x+1);
                temp.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n,false);
        vector<int> temp;
        vector<vector<int>> result;
        permutation(temp,result,visited,nums,n,0);
        return result;
    }
};
