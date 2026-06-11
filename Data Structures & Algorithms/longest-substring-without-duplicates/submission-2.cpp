class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, m = 0;
        unordered_set<char> c;
        for(int r = 0; r < s.length(); r++){
            while(c.find(s[r]) != c.end()){
                c.erase(s[l]);
                l++;
            }
            c.insert(s[r]);
            m = max(m, r-l+1);
        }
        return m;
    }
};
