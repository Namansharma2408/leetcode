class FindSumPairs {
public:
    unordered_map<int,int> mp1;
    unordered_map<int,int> mp2;
    vector<int> nums2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums2 = nums2;
        int n = nums1.size();
        for( int i = 0 ; i < n ; i++) mp1[nums1[i]]++;
        n = nums2.size();
        for( int i = 0 ; i < n ; i++) mp2[nums2[i]]++;
    }
    
    void add(int idx, int val) {
        int num = nums2[idx];
        mp2[num]--;
        mp2[num+val]++;
        nums2[idx] += val;
    }
    
    int count(int tot) {
        int ans = 0;
        for( auto p : mp1){
            ans += (p.second)*(mp2[tot-p.first]);
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
