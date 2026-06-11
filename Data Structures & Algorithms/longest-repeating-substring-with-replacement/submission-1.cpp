class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, maxLen = 0, maxFreq = 0;
        vector<int> f(26, 0);
        for(int r = 0; r < s.length(); r++){
            f[s[r] - 'A']++;
            maxFreq = max(maxFreq, f[s[r] - 'A']);
            while((r-l+1) - maxFreq > k){
                f[s[l] - 'A']--;
                l++;
            } 
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};
