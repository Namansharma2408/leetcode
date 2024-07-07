class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector <string> v;
         
        for( int i = 0 ; i < n ; i++){
            if( (i+1)%15 == 0) v.push_back("FizzBuzz");
            else if( (i+1)%5 == 0) v.push_back("Buzz");
            else if( (i+1)%3 == 0) v.push_back("Fizz");
            else{
                string s = to_string(i+1);
                v.push_back(s);
            }
        }
        return v;
    }
};
