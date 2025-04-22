class Solution {
public:
    int minPartitions(string n) {
        int size = n.size();
        int maxi = -1;
        for( int i = 0 ; i < size ; i++) maxi = max(maxi,(n[i]-48));
        return maxi;
    }
};
