class Solution {
public:
    int partition(vector<int>& arr, int left, int right) {
        int randomIndex = left + rand() % (right - left + 1); 
        swap(arr[randomIndex], arr[right]); 
        int pivot = arr[right];
        int i = left;
        for (int j = left; j < right; j++) {
            if (arr[j] < pivot) {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[right]);
        return i;
    }

    int quickSelect(vector<int>& arr, int left, int right, int k) {
        if (left == right) return arr[left];

        int pivotIndex = partition(arr, left, right);

        if (k == pivotIndex)
            return arr[k];
        else if (k < pivotIndex)
            return quickSelect(arr, left, pivotIndex - 1, k);
        else
            return quickSelect(arr, pivotIndex + 1, right, k);
    }

    int findMedian(vector<int>& arr) {
        int n = arr.size();
        if (n % 2 == 1)
            return quickSelect(arr, 0, n - 1, n / 2); // Odd size
        else
            return (quickSelect(arr, 0, n - 1, n / 2 - 1) +
                    quickSelect(arr, 0, n - 1, n / 2)) / 2; // Even size
    }
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        if( m == 1 && n == 1) return 0;
        int rem = grid[0][0]%x;
        for( auto i : grid) for( int j : i) if(j%x != rem) return -1;        
        vector<int> v(m*n,-1);
        int k = 0;
        for( auto i : grid) for( int j : i) v[k++] = j;       
        int median =  findMedian(v);
        int ans = 0;
        for( int i : v) ans += abs(median - i);
        return ans/x;
    }
};
