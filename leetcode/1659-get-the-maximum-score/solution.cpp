class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        // common nikalo 
        vector<int> common;
        int mod = 1000000007;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int j = 0;
        while(i < n1 && j < n2){
            if(nums1[i] == nums2[j]) {
                common.push_back(nums1[i]);
                i++,j++;
            }
            else if( nums1[i] < nums2[j]) i++;
            else j++;
        }
        common.push_back(0);
        
        // 1st array ke operations 
        i = 0;
        j = 0;
        long long sum = 0;
        vector<long long> ans;
        while( i < n1){
            sum += nums1[i]; 
            if( j < common.size() && nums1[i] == common[j]){
                ans.push_back(sum);
                j++;
                sum = 0;
            }
            i++;
        }
        ans.push_back(sum);
        
        // 2nd array ke operations
        i = 0;
        j = 0;
        sum = 0;
        while( i < n2){
            sum += nums2[i];
            if( j < common.size() && nums2[i] == common[j]){
                ans[j] = (ans[j] > sum ? ans[j] : sum);
                j++;
                sum = 0;
            }
            i++;
        }
        ans[ans.size()-1] = (ans[ans.size()-1] > sum ? ans[ans.size()-1] : sum);
        sum = 0;
        for(long long i : ans){
            sum += i;
            sum %= mod;
        }
        
        return (int)sum;
    }
};
