class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int Hs = 0 , He = n-1 , Vs = 0 , Ve = m-1 ;
		int count = 0;
        vector<int> arr;
		while(count <= m*n){
			for( int i = Hs ; i <= He ; i++ ){			
			if( count >= m*n )break;
			arr.push_back(matrix[Vs][i]);
            count++;
			}
			if( count >= m*n )break;
			Vs++;
			for( int i = Vs ; i <= Ve ; i++ ){			
			if( count >= m*n )break;
			arr.push_back(matrix[i][He]);
            count++;
			}
			if( count >= m*n )break;
			He--;
			for( int i = He ; i >= Hs  ; i-- ){		
			if( count >= m*n )break;
			arr.push_back(matrix[Ve][i]);
            count++;
			}
			if( count >= m*n )break;
			Ve--;
			for( int i = Ve ; i >= Vs ; i-- ){
			if( count >= m*n )break;
			arr.push_back(matrix[i][Hs]);
            count++;
			}
			if( count >= m*n )break;
			Hs++;	
		} 
        return arr;
    }
};
