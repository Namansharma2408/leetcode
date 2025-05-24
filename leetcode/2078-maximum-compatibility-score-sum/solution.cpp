class Solution {
public:
    int maxi = INT_MIN;
    void backTrack(vector<vector<int>> &v,vector<bool> &check,int &currSum,int row,int n){
        if( row == n ){
            cout<<currSum<<endl;
            if( maxi < currSum ) maxi = currSum;
            return;
        }        
        
        for( int i = 0 ; i < n ; i++){
            if( check[i] ){
                currSum += v[row][i];
                check[i] = false;
                backTrack(v,check,currSum,row+1,n);
                currSum -= v[row][i];
                check[i] = true;
            }
        }
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();
        int n = students[0].size();
        vector<vector<int>> v(m,vector<int>(m,0));
        for( int i = 0 ; i < m ; i++){
            for( int j = 0 ; j < m ; j++){
                for( int k = 0 ; k < n ; k++){
                    if( students[i][k] == mentors[j][k]) v[i][j]++;
                }
            }
        }      
        int currSum = 0;
        int row = 0;
        vector<bool> check(m,true);
        backTrack(v,check,currSum,row,m);
        return maxi;
    }
};
