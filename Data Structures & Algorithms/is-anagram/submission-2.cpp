class Solution {
public:
    bool isAnagram(string s, string t) {
        int k = 0;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
