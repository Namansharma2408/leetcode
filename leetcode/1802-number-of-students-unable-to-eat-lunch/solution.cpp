class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int stud0 = 0;
        int stud1 = 0;
        for( int i = 0 ; i < n ; i++ ){
            if( students[i] == 0 ) stud0++;
            else stud1++;
        }
        for( int i = 0 ; i < n ; i++ ){
            if( sandwiches[i] == 1 ) stud1--;
            else stud0--;
            if( stud1 < 0 || stud0 < 0 ){
                return n-i;
            }
        }
        return 0;
    }
};
