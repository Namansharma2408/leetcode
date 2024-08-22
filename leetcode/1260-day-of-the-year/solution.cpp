class Solution {
public:
    int dayOfYear(string date) {
        int y = stoi(date.substr(0,4));
        int m = stoi(date.substr(5,2));
        int d = stoi(date.substr(8,2)); 
        int arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if( y == 1900){
            arr[1] = 28;
            for( int i = 1 ; i < m ; i++){
                d += arr[i-1];
            }
        }
        else if( y%4 != 0){
            for( int i = 1 ; i < m ; i++){
                d += arr[i-1];
            }
        }
        else{
            arr[1] = 29;
            for( int i = 1 ; i < m ; i++){
                d += arr[i-1];
            }
        }
        return d;
    }
};
