class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        bool sum = 0;
        for( int i : derived) if( i == 1) sum = !sum;
        return sum==0;
    }
};
