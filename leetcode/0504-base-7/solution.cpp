class Solution {
public:
    string convertToBase7(int num) {
        string str = "";
        if( num == 0) return "0";
        else if ( num > 0){
            while( num != 0){
                str = to_string(num%7) + str;
                num /= 7;
            } 
            return str;          
        }
        else{
            num = -num;
            while( num != 0){
                str = to_string(num%7) + str;
                num /= 7;
            } 
            return ("-" + str); 
        }
    }
};
