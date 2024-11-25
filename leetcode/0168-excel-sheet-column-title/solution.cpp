class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s = "";
        while( columnNumber != 0){
            if((columnNumber%26) != 0) s =  (char)((columnNumber%26)+64) + s;
            else s = 'Z' + s,columnNumber -= 26 ;
            columnNumber /= 26;
        }
        return s;
    }
};
