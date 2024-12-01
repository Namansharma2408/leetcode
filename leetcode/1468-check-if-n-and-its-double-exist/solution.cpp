class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int p = 0;
        for( int k = 0 ; k < n ; k++){
            if( arr[k] >= 0){
                p = k;
                break;
            }
        }

        int lo = p;
        int hi = n-1;
        int mid;
        for( int i = p ; i < n-1 ; i++){
            while( lo <= hi){
                mid = (lo+hi)/2;
                if( arr[i] == 0 && arr[mid] == 0 && i != mid) return true;
                if(arr[i] != 0 && 2*arr[i] == arr[mid]) return true;
                else if( 2*arr[i] < arr[mid]) hi = mid-1;
                else lo = mid+1;
            }
            lo = p;
            hi = n-1;
        }
        lo = 0;
        hi = p-1;
        mid;
        for( int i = 0 ; i < p-1 ; i++){
            while( lo <= hi){
                mid = (lo+hi)/2;
                if(arr[i] != 0 && arr[i] == 2*arr[mid]) return true;
                else if( arr[i] < 2*arr[mid]) hi = mid-1;
                else lo = mid+1;
            }
            lo = 0;
            hi = p-1;
        }
        return false;
    }
};
