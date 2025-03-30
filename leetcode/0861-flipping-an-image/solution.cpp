class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        cout<<n<<endl;
        for( auto& i : image){
            for( int j = 0 ; j < n/2 ; j++){
                if( i[j] == i[n-j-1] ){
                    i[j] = !i[j];
                    i[n-j-1] = !i[n-j-1];
                }
            }
            if( n%2 == 1) i[n/2] = !i[n/2];
        }
        return image;
    }
};
