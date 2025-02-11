class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> num1;
        int n = nums1.size();
        for( int i = 0 ; i < n ; i++) num1[nums1[i]]++;
        unordered_map<int,int> num2;
        n = nums2.size();
        for( int i = 0 ; i < n ; i++) num2[nums2[i]]++;
        vector<int> ans;
        for( auto i : num1){
            if( num2.find(i.first) != num2.end()){
                ans.push_back(i.first);
                if(num2[i.first]) num2[i.first]--;
                else num2.erase(i.first);
            }
        }
        return ans;

    }
};
