class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, longest = 0;
        unordered_set<char> st;
        for(int r = 0; r < s.length(); r++){
            while(st.find(s[r]) != st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            longest = max(longest, (r-l+1));
        }
        return longest;
    }
};
