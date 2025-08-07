class Solution {
public:
    int trap(vector<int>& height) {
        int maxidx = 0;
        int n = height.size();
        long long sum = 0;
        for( int i = 0 ; i < n ; i++){
            sum += height[i];
            if(height[i] > height[maxidx]) maxidx = i;
        }
        int maxi = 0;
        for( int i = 0 ; i < maxidx ; i++){
            if(height[i] > maxi ) maxi = height[i];
            height[i] = maxi;
        }
        maxi = 0;
        for( int i = n-1 ; i > maxidx ; i--){
            if(height[i] > maxi ) maxi = height[i];
            height[i] = maxi;
        }
        for( int i = 0 ; i < n ; i++){
            sum -= height[i];
        }
        int ans = -sum;
        return ans;
        
        
    }
};
