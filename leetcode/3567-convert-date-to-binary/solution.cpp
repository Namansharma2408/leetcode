class Solution {
public:
    string stringToBinary(string s){
        int n = stoi(s);
        s.clear();
        while(  n != 0){
            if(n%2 == 0)s = '0' + s ;
            else s = '1' + s ;
            n /= 2;
        }
        return s;
    }
    string convertDateToBinary(string date) {
        cout<<date<<endl;
        date += stringToBinary(date.substr(0,4)) + '-';
        cout<<date<<endl;
        date += stringToBinary(date.substr(5,2)) + '-';
        date += stringToBinary(date.substr(8,2));
        date = date.substr(10);
        return date;
    }
};
