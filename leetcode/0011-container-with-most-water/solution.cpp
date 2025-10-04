class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int i = 0;
        int j = n - 1;
        int maxArea = 0;
        while( i < j ){
            maxArea = max(maxArea, (min(h[i],h[j]) * (j-i)));
            if( h[i] < h[j] ) i++;
            else j--;
        }

        return maxArea;
    }
};
