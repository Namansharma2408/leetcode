class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count = 0;
        int i = 0;
        int j = i+1;
        int k = j+1 ;
        for( i=0 ; i < j ; i++)for( j = i + 1 ; j < k;  j++)for( k = j + 1 ; k < arr.size();  k++){
            if( abs(arr[i] - arr[j]) <= a && abs(arr[k] - arr[j]) <= b && abs(arr[i] - arr[k]) <= c)count++;            
        }
        return count;
    }
};
