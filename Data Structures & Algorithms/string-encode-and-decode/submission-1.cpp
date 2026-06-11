class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(int i = 0; i < strs.size(); i++){
            s += to_string(strs[i].length()) + "#" + strs[i];
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> st;
        int i = 0;
        while (i < s.length()) {
            int pos = s.find('#', i);
            int len = stoi(s.substr(i, pos - i));
            st.push_back(s.substr(pos + 1, len));
            i = pos + 1 + len;
        }
        return st;
    }
};
