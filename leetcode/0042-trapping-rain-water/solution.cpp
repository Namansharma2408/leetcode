class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxi = 0;
        int curr = height[0];
        for( int i = 1 ; i < n ; i++ ){
            if( height[i] > height[maxi] ) maxi = i;
            curr += height[i];
        }
        for( int i = 1 ; i < maxi ; i++ ){
            height[i] = max(height[i],height[i-1]);
        }
        for( int i = n-2 ; i > maxi ; i-- ){
            height[i] = max(height[i],height[i+1]);
        }

        int ans = 0;
        for( int i = 0 ; i < n ; i++ ){
            ans += height[i];
        }
        ans -= curr;
        return ans;
    }
};
