class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> mp;
        for( int i : nums) mp[i]++;
        int maxi = -1;
        int maxNum = -1;
        for( auto i : mp ) if( maxi < i.second){ 
            maxi = i.second;
            maxNum = i.first;
        }
        int n = nums.size();
        int firstHalf = 0;
        int secondHalf = maxi;
        for( int i = 0 ; i < n ; i++){
            if( nums[i] == maxNum ){
                firstHalf++;
                secondHalf--;
                if( firstHalf == 0 || secondHalf == 0) continue;
                if((i+1) / firstHalf == 1 && (n-i-1)/secondHalf == 1) return i;;
            }
        }
        return -1;

        
    }
};
