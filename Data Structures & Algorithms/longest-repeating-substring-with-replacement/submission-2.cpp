class Solution {
public:
    int characterReplacement(string s, int k) {
        int longest = 0, l = 0, maxFreq = 0;
        vector<int> f(26, 0);
        for(int r = 0; r < s.length(); r++){
            f[s[r] - 'A']++;
            maxFreq = max(maxFreq, f[s[r] - 'A']);
            while((r-l+1) - maxFreq > k){
                f[s[l] - 'A']--;
                l++;
            }
            longest = max(longest, (r-l+1));
        }
        return longest;
    }
};
