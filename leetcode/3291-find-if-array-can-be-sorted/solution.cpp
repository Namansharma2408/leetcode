class Solution {
public:
    int setBits(int n){
        int ans = 0;
        while( n!=0){
            if( n%2 == 1) ans++;
            n /= 2;
        }
        return ans;
    }
    vector<int> minMax( vector<int> &nums,int i,int j){
        vector<int> ans(2);
        if( i == j){
            ans[0] = nums[i];
            ans[1] = nums[i];
            return ans;
        }
        ans[0] = INT_MAX;
        ans[1] = INT_MIN;
        int n = nums.size();
        for( int k = i ; k < j ; k+=2) if(nums[k] > nums[k+1]) swap(nums[k],nums[k+1]);
        for( int k = i ; k  < j ; k+=2){
            ans[0] = min(ans[0],nums[k]);
            ans[1] = max(ans[1],nums[k+1]);
        }
        ans[0] = min(ans[0],nums[j]);
        ans[1] = max(ans[1],nums[j]);
        return ans;
    }
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        bool sorted = true;
        for( int i = 0 ; i < n-1 ; i++) if( nums[i] > nums[i+1]) sorted = false;;
        if( sorted ) return true;
        vector<int> sb(n);
        for( int i = 0 ; i < n ; i++) sb[i] = setBits(nums[i]);
        vector<int> ans;
        int i = 0;
        int j = 0;
        while( i < n ){
            j = i;
            while( j < n ){
                if( sb[j] != sb[i]) break;
                j++;
            }
            vector<int> v = minMax(nums,i,j-1);
            i = j;
            ans.insert(ans.end(),v.begin(),v.end());
        }
        for( int i = 1 ; i < ans.size()-1 ; i += 2) if( ans[i] > ans[i+1]) return false;
        return true;


    }
};
