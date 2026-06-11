class Solution {
public:
    string minWindow(string s, string t) {
        string a = "";
        if(s.length() < t.length()) return a;
        unordered_map<char, int> mp; 
        unordered_map<char, int> wFreq;
        for(char c : t){
            mp[c]++;
        } 
        int form = 0, req = mp.size();
        int l = 0, k = 0, m = s.length()+1;
        for(int r = 0; r < s.length(); r++){
            wFreq[s[r]]++;
            if(mp.find(s[r]) != mp.end() && wFreq[s[r]] == mp[s[r]]) form++;
            while(form == req){
                if((r-l+1) < m){
                    m = r-l+1;
                    k = l;
                }
                wFreq[s[l]]--;
                if(mp.find(s[l]) != mp.end() && wFreq[s[l]] < mp[s[l]]){
                    form--;
                }
                l++;
            }
        }
        if(m == s.length()+1) return a;
        else return s.substr(k, m);
    }
};
