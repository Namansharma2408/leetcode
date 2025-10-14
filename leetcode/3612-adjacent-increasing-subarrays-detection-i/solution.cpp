class Solution {
public:
    bool checkKinc(int idx, vector<int> &nums, int k){
        for( int i = idx ; i < idx + k - 1 ; i++ ){
            if( nums[i]  >= nums[i+1] ) return false;
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int>st;
        if( k == 1 && n >= 2 ) return true;
        for( int i = 0 ; i < n - k + 1; i++){
            if(checkKinc(i,nums,k) )
                st.insert(i); 
        }

        for( int i : st ){
            if(st.find(i+k) != st.end())  return true;
            if(st.find(i-k) != st.end())  return true;
        }

        return false;
    }
};
