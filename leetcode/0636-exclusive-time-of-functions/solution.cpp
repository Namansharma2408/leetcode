class Solution {
public:
    pair<bool, pair<int, int>> extract(string str) {
        int id = 0;
        int idx = 0;
        while (str[idx] != ':') {
            id *= 10;
            id += (str[idx] - '0');
            idx++;
        }
        int time = 0;
        idx = str.size() - 1;
        int p = 1;
        while (str[idx] != ':') {
            time += p * (str[idx] - '0');
            p *= 10;
            idx--;
        }
        idx--;
        bool b;
        if (str[idx] == 't')
            b = true;
        else
            b = false;
        return {b, {id, time}};
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;
        int m = logs.size();
        vector<int> v(n, 0);
        for (int i = 0; i < m; i++) {
            pair<bool, pair<int, int>> p = extract(logs[i]);
            if (p.first) {
                if (!st.empty())
                    v[st.top()] += p.second.second;
                // for (int i = 0; i < n; i++) {
                //     cout << v[i] << " ";
                // }
                // cout << endl << endl;
                st.push(p.second.first);
                v[st.top()] -= p.second.second;
                // for (int i = 0; i < n; i++) {
                //     cout << v[i] << " ";
                // }
                // cout << endl << endl;
            } else {
                v[st.top()] += p.second.second + 1;
                // for (int i = 0; i < n; i++) {
                //     cout << v[i] << " ";
                // }
                // cout << endl << endl;
                st.pop();
                if (!st.empty())
                    v[st.top()] -= (p.second.second+1);
                // for (int i = 0; i < n; i++) {
                //     cout << v[i] << " ";
                // }
                // cout << endl << endl;
            }
        }
        return v;
    }
};
