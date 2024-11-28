class Solution {
public:
    void remove(vector<vector<int>> &vec){
        
        for (auto &innerVec : vec) { 
            sort(innerVec.begin(), innerVec.end()); 
        }            
        sort(vec.begin(), vec.end()); 
        auto last = unique(vec.begin(), vec.end()); 
        vec.erase(last, vec.end());
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> v(3);
        int n = nums.size();
        for(int i = 0 ; i < n-2 ; i++){
            if( nums[i] == 0){
                if( nums[i+1] == 0 && nums[i+2] == 0){
                    v[0] = 0,v[1] = 0,v[2] = 0;
                    ans.push_back(v);
                }
            }
        }
        for( int i = 0; nums[i] < 0 && i < n ; i++){
            for( int j = n-1 ; nums[j] > 0 && j >= 0 ; j--){                
                    int k = - nums[j] - nums[i];
                    int hi = j-1;
                    int lo = i+1;
                    int mid = 0;
                    while(lo <= hi ){
                        mid = (lo + hi)/2;
                        if( nums[mid] == k){
                            v[0] = nums[i];
                            v[1] = nums[mid];
                            v[2] = nums[j];
                            ans.push_back(v);
                            break;
                        } 
                        else if(nums[mid] < k) lo = mid+1;
                        else hi = mid-1;
                    }
                
            }
        }
        remove(ans);
        return ans;
        
    }
};
