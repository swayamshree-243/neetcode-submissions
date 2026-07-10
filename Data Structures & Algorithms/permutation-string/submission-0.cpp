class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        vector<int> s1Freq(26, 0);
        vector<int> s2Freq(26, 0);
        for(char c : s1){
            s1Freq[c - 'a']++;
        }
        int k = s1.length();
        for(int i = 0; i < k; i++){
            s2Freq[s2[i] - 'a']++;
        }
        int l = 0;
        for(int r = k; r < s2.length(); r++){
            if(s1Freq == s2Freq) return true;
            s2Freq[s2[l] - 'a']--;
            s2Freq[s2[r] - 'a']++;
            l++;
        }
        if(s1Freq == s2Freq) return true;
        else return false;
    }
};
