class Solution {
public:
    string str;
    string result;
    void fun(int n, int &k) {
        if (n == 0) {
            k--;
            if (k == 0)
                result = str;
            return;
        }
        if (k <= 0)
            return;
        if (!str.size()) {
            str.push_back('a');
            fun(n - 1, k);
            str.pop_back();
            str.push_back('b');
            fun(n - 1, k);
            str.pop_back();
            str.push_back('c');
            fun(n - 1, k);
            str.pop_back();
        } else {
            char ch = str[str.size() - 1];
            if (ch != 'a') {
                str.push_back('a');
                fun(n - 1, k);
                str.pop_back();
            }
            if (ch != 'b') {
                str.push_back('b');
                fun(n - 1, k);
                str.pop_back();
            }
            if (ch != 'c') {
                str.push_back('c');
                fun(n - 1, k);
                str.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        fun(n, k);
        return result;
    }
};
